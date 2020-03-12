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

fn main() {
    let res = match clap::App::new("cmplib")
        .about("compro-library CLI")
        .version("0.0.1")
        .subcommand(clap::App::new("snip").about("generate VSCode's snippets"))
        .get_matches()
        .subcommand_name()
    {
        Some("snip") => std::fs::write(
            "cpp.json",
            serde_json::to_string_pretty(
                &serde_yaml::from_str::<Vec<Package>>(&std::fs::read_to_string("lib.yml").unwrap())
                    .unwrap()
                    .iter()
                    .map(|package| {
                        package.modules.iter().map(move |module| {
                            let doc = std::fs::read_to_string(format!(
                                "lib/{package}/{module}/README.md",
                                package = package.package,
                                module = module
                            ))
                            .unwrap();
                            let meta = regex::Regex::new(
                                r"snippet's prefix: (?P<prefix>\$.*)\n(?P<description>.*)",
                            )
                            .unwrap()
                            .captures(&doc)
                            .unwrap();
                            let src = std::fs::read_to_string(format!(
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
                            let snippet = regex::Regex::new(r"var_(\w+)")
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
                            (
                                module,
                                Snippet {
                                    prefix: meta.name("prefix").unwrap().as_str().to_string(),
                                    description: meta
                                        .name("description")
                                        .unwrap()
                                        .as_str()
                                        .to_string(),
                                    body: snippet
                                        .iter()
                                        .map(|line| line[indent_size..].to_string())
                                        .collect::<Vec<String>>(),
                                },
                            )
                        })
                    })
                    .flatten()
                    .collect::<std::collections::BTreeMap<_, _>>(),
            )
            .unwrap(),
        ),
        _ => {
            println!("abc");
            Ok(())
        }
    };
    if res.is_err() {
        panic!("error");
    }
}
