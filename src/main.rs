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

#[derive(serde::Deserialize, Debug)]
struct AOJHeader {
    serial: i64,
    name: String,
    #[serde(rename(deserialize = "inputSize"))]
    input_size: i64,
    #[serde(rename(deserialize = "outputSize"))]
    output_size: i64,
    score: i64,
}

#[derive(serde::Deserialize, Debug)]
struct AOJHeaderInfo {
    #[serde(rename(deserialize = "problemId"))]
    problem_id: String,
    headers: Vec<AOJHeader>,
}

#[derive(serde::Deserialize, Debug)]
struct AOJTestCase {
    #[serde(rename(deserialize = "problemId"))]
    problem_id: String,
    serial: i64,
    #[serde(rename(deserialize = "in"))]
    input: String,
    #[serde(rename(deserialize = "out"))]
    output: String,
}

#[tokio::main]
async fn main() -> Result<(), Box<dyn std::error::Error>> {
    match clap::App::new("cmplib")
        .about("compro-library CLI")
        .version("0.0.1")
        .subcommand(clap::App::new("snip").about("generate VSCode's snippets"))
        .subcommand(
            clap::App::new("fetch")
                .about("fetch test cases from AOJ")
                .arg(
                    clap::Arg::with_name("id")
                        .help("AOJ's problem ID")
                        .takes_value(true)
                        .required(true),
                )
                .arg(
                    clap::Arg::with_name("package")
                        .help("package to be added test suite")
                        .takes_value(true)
                        .required(true),
                )
                .arg(
                    clap::Arg::with_name("module")
                        .help("module to be added test suite")
                        .takes_value(true)
                        .required(true),
                ),
        )
        .get_matches()
        .subcommand()
    {
        ("snip", _) => {
            std::fs::write(
                "cpp.json",
                serde_json::to_string_pretty(
                    &serde_yaml::from_str::<Vec<Package>>(
                        &std::fs::read_to_string("lib.yml").unwrap(),
                    )
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
            )?;
            Ok(())
        }
        ("fetch", Some(fetch_matches)) => {
            let id = fetch_matches.value_of("id").unwrap();
            let header_info = reqwest::get(&format!(
                "https://judgedat.u-aizu.ac.jp/testcases/{}/header",
                id
            ))
            .await?
            .json::<AOJHeaderInfo>()
            .await?;
            let package = fetch_matches.value_of("package").unwrap();
            let module = fetch_matches.value_of("module").unwrap();
            let dir = format!("lib/{}/{}/{}", package, module, id);
            std::fs::create_dir_all(format!("{}/in", dir))?;
            std::fs::create_dir_all(format!("{}/out", dir))?;
            for header in header_info.headers {
                let testcase = reqwest::get(&format!(
                    "https://judgedat.u-aizu.ac.jp/testcases/{}/{}",
                    id, header.serial
                ))
                .await?
                .json::<AOJTestCase>()
                .await?;
                if !testcase.input.contains("terminated") && !testcase.output.contains("terminated")
                {
                    std::fs::write(format!("{}/in/{}", dir, header.serial), &testcase.input)?;
                    std::fs::write(format!("{}/out/{}", dir, header.serial), &testcase.output)?;
                }
            }
            Ok(())
        }
        _ => Ok(()),
    }
}
