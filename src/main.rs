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
    let res = std::fs::write(
        "cpp.json",
        serde_json::to_string_pretty(
            &serde_yaml::from_str::<Vec<Package>>(&std::fs::read_to_string("lib.yml").unwrap())
                .unwrap()
                .iter()
                .map(|package| {
                    package.modules.iter().map(move |module| {
                        let src = std::fs::read_to_string(format!(
                            "lib/{package}/{module}/{module}.cpp",
                            package = package.package,
                            module = module
                        ))
                        .unwrap();
                        (
                            module,
                            Snippet {
                                prefix: "tst".to_string(),
                                description: "first snippet".to_string(),
                                body: regex::Regex::new(r"var_(\w+)")
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
                                    .skip_while(|&line| line != "// begin")
                                    .skip(1)
                                    .take_while(|&line| line != "// end")
                                    .map(&str::to_string)
                                    .collect::<Vec<String>>(),
                            },
                        )
                    })
                })
                .flatten()
                .collect::<std::collections::BTreeMap<_, _>>(),
        )
        .unwrap(),
    );
    if res.is_err() {
        panic!("error");
    }
}
