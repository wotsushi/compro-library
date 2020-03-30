use itertools::Itertools;

#[derive(serde::Serialize)]
struct Snippet {
    prefix: String,
    description: String,
    body: Vec<String>,
}

#[derive(serde::Deserialize)]
struct Package {
    package: String,
    modules: Vec<String>,
}

pub fn write_snippet() -> Result<(), Box<dyn std::error::Error>> {
    std::fs::write(
        "cpp.json",
        generate_snippet(std::fs::read_to_string::<String>).unwrap(),
    )?;
    Ok(())
}

fn generate_snippet(
    read_to_string: fn(String) -> std::io::Result<String>,
) -> serde_json::Result<String> {
    serde_json::to_string_pretty(
            &serde_yaml::from_str::<Vec<Package>>(&read_to_string("lib.yml".to_string()).unwrap())
                .unwrap()
                .iter()
                .map(|package| {
                    package.modules.iter().map(move |module| {
                        let doc = read_to_string(format!(
                            "lib/{package}/{module}/README.md",
                            package = package.package,
                            module = module
                        ))
                        .unwrap();
                        let meta = regex::Regex::new(
                            r"version: (?P<version>\d+\.\d+)\nsnippet's prefix: (?P<prefix>\$.*)\n(?P<description>.*)",
                        )
                        .unwrap()
                        .captures(&doc)
                        .unwrap();
                        let src = read_to_string(format!(
                            "lib/{package}/{module}/{module}.{ext}",
                            package = package.package,
                            module = module,
                            ext = if package.package == "snippet" {
                                "cpp"
                            } else {
                                "hpp"
                            }
                        ))
                        .unwrap();
                        let mut snippet = regex::Regex::new(r"var_(\w+)")
                            .unwrap()
                            .captures_iter(&src)
                            .map(|cap| (cap[0].to_string(), cap[1].to_string()))
                            .unique()
                            .enumerate()
                            .collect::<Vec<_>>()
                            .iter()
                            .fold(src, |s, (i, (var, name))| {
                                s.replace(
                                    var,
                                    &format!(
                                        "${{{index}:{identifier}}}",
                                        index = i + 1,
                                        identifier = name
                                    ),
                                )
                            })
                            .split("\n")
                            .skip_while(|&line| !line.ends_with("// begin"))
                            .skip(1)
                            .take_while(|&line| !line.ends_with("// end"))
                            .map(&str::to_string)
                            .collect::<Vec<String>>();
                        let (indent_size, _) = snippet[0]
                            .chars()
                            .enumerate()
                            .find(|&(_, c)| c != ' ')
                            .unwrap();
                        snippet = snippet.iter().map(|line| line[indent_size..].to_string()).collect::<Vec<String>>();
                        snippet.insert(
                            0,
                            format!(
                                "#pragma region {} {}",
                                module,
                                meta.name("version").unwrap().as_str()
                            ),
                        );
                        snippet.push(format!("#pragma endregion {}", module));
                        (
                            module,
                            Snippet {
                                prefix: meta.name("prefix").unwrap().as_str().to_string(),
                                description: meta.name("description").unwrap().as_str().to_string(),
                                body: snippet,
                            },
                        )
                    })
                })
                .flatten()
                .collect::<std::collections::BTreeMap<_, _>>(),
        )
}

#[test]
fn test_generate_snippet() {
    fn read_to_string(path: String) -> std::io::Result<String> {
        match path.as_str() {
            "lib.yml" => Ok("- package: snippet
  modules:
    - template
    - precision
- package: struct
  modules:
    - mint
"
            .to_string()),
            "lib/snippet/template/README.md" => Ok("# テンプレート

version: 1.0
snippet's prefix: $t
hoge

## 説明
hogehoge
"
            .to_string()),
            "lib/snippet/template/template.cpp" => Ok("// begin
#include <bits/stdc++.h>
using namespace std;
// end
int test = []() {
    // ll
    {
        ll actual = 12345678901;
        long long expected = 12345678901;
        assert(actual == expected);
    }

    return 0;
}();
"
            .to_string()),
            "lib/snippet/precision/README.md" => Ok("# 浮動小数点数の標準出力

version: 0.1
snippet's prefix: $p
foo

## 説明
foobar
"
            .to_string()),
            "lib/snippet/precision/precision.cpp" => Ok("string precision(ll var_15, double var_x)
{
    ostringstream cout;
    // begin
    cout << fixed << setprecision(var_15) << var_x << endl;
    // end
    return cout.str();
}
"
            .to_string()),
            "lib/struct/mint/README.md" => Ok("# ModInt

version: 1.0
snippet's prefix: $mint
mintです

## 説明
mint最高
"
            .to_string()),
            "lib/struct/mint/mint.hpp" => Ok("ll var_MOD = 1e9 + 7;

// begin
struct mint
{
    ll a;

    mint(ll x = 0) : a((x % var_MOD + var_MOD) % var_MOD) {}
}
// end
"
            .to_string()),
            _ => Err(std::io::Error::new(
                std::io::ErrorKind::NotFound,
                format!("unexpected path is specified: {}", path),
            )),
        }
    }
    let actual = generate_snippet(read_to_string).unwrap();
    let expected = "{
  \"mint\": {
    \"prefix\": \"$mint\",
    \"description\": \"mintです\",
    \"body\": [
      \"#pragma region mint 1.0\",
      \"struct mint\",
      \"{\",
      \"    ll a;\",
      \"\",
      \"    mint(ll x = 0) : a((x % ${1:MOD} + ${1:MOD}) % ${1:MOD}) {}\",
      \"}\",
      \"#pragma endregion mint\"
    ]
  },
  \"precision\": {
    \"prefix\": \"$p\",
    \"description\": \"foo\",
    \"body\": [
      \"#pragma region precision 0.1\",
      \"cout << fixed << setprecision(${1:15}) << ${2:x} << endl;\",
      \"#pragma endregion precision\"
    ]
  },
  \"template\": {
    \"prefix\": \"$t\",
    \"description\": \"hoge\",
    \"body\": [
      \"#pragma region template 1.0\",
      \"#include <bits/stdc++.h>\",
      \"using namespace std;\",
      \"#pragma endregion template\"
    ]
  }
}"
    .to_string();
    assert_eq!(expected, actual);
}
