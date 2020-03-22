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

enum TestError {
    CompileError(String),
    RuntimeError(String),
    WrongAnswer {
        testcase: String,
        actual: String,
        expected: String,
    },
}

impl std::fmt::Display for TestError {
    fn fmt(&self, f: &mut std::fmt::Formatter) -> std::fmt::Result {
        match self {
            TestError::CompileError(msg) => write!(
                f,
                "{}: {}",
                ansi_term::Colour::Red.paint("Compile Error"),
                msg
            ),
            TestError::RuntimeError(msg) => write!(
                f,
                "{}: {}",
                ansi_term::Colour::Red.paint("Runtime Error"),
                msg
            ),
            TestError::WrongAnswer {
                testcase,
                actual,
                expected,
            } => write!(
                f,
                "{}(#{}): actual = {}, expected = {}",
                ansi_term::Colour::Red.paint("Wrong Answer"),
                testcase,
                actual,
                expected
            ),
        }
    }
}
impl std::fmt::Debug for TestError {
    fn fmt(&self, f: &mut std::fmt::Formatter) -> std::fmt::Result {
        <dyn std::fmt::Display>::fmt(self, f)
    }
}

impl std::error::Error for TestError {}

fn compile(dir: &str, module: &str) -> Option<String> {
    let err = std::process::Command::new("g++-9")
        .arg(format!("{}/{}.cpp", dir, module))
        .arg("-o")
        .arg(format!("{}/{}.out", dir, module))
        .output()
        .unwrap()
        .stderr;
    if err.is_empty() {
        None
    } else {
        Some(String::from_utf8(err).unwrap())
    }
}

fn test_module(package: &str, module: &str) -> Result<(), Box<dyn std::error::Error>> {
    let dir = format!("lib/{}/{}", package, module);

    // handmade
    if let Some(err) = compile(&dir, &module) {
        return Err(Box::new(TestError::CompileError(err)));
    }
    println!(
        "{}: {}/{}.cpp",
        ansi_term::Colour::Green.paint("Compile succeeded"),
        dir,
        module
    );
    let res = std::process::Command::new(format!("{}/{}.out", dir, module))
        .output()
        .unwrap();
    if !res.stderr.is_empty() {
        return Err(Box::new(TestError::RuntimeError(
            String::from_utf8(res.stderr.to_vec()).unwrap(),
        )));
    }
    println!("{}", ansi_term::Colour::Green.paint("Test passed"));

    // test suite
    for entry in std::fs::read_dir(&dir).unwrap() {
        let entry = entry.unwrap();
        if entry.file_type().unwrap().is_dir() {
            let suite_dir = format!("{}/{}", dir, entry.file_name().into_string().unwrap());
            if let Some(err) = compile(&suite_dir, &module) {
                return Err(Box::new(TestError::CompileError(err)));
            }
            println!(
                "{}: {}/{}.cpp",
                ansi_term::Colour::Green.paint("Compile succeeded"),
                dir,
                module
            );
            let mut suite_entries = std::fs::read_dir(format!("{}/in", suite_dir))
                .unwrap()
                .map(|entry| entry.unwrap())
                .collect::<Vec<_>>();
            suite_entries.sort_by_key(|entry| entry.path());
            for suite_entry in suite_entries {
                let testcase = suite_entry.file_name().into_string().unwrap();
                let res = std::process::Command::new(format!("{}/{}.out", suite_dir, module))
                    .stdin(std::fs::File::open(format!("{}/in/{}", suite_dir, testcase)).unwrap())
                    .output()
                    .unwrap();
                if !res.stderr.is_empty() {
                    return Err(Box::new(TestError::RuntimeError(
                        String::from_utf8(res.stderr.to_vec()).unwrap(),
                    )));
                }
                let actual = String::from_utf8(res.stdout.to_vec()).unwrap();
                let expected =
                    std::fs::read_to_string(format!("{}/out/{}", suite_dir, testcase)).unwrap();
                if actual != expected {
                    return Err(Box::new(TestError::WrongAnswer {
                        testcase,
                        actual,
                        expected,
                    }));
                }
                println!(
                    "{}: {}",
                    ansi_term::Colour::Green.paint("Test passed"),
                    testcase
                );
            }
        }
    }
    Ok(())
}

fn test_package(package: &str) -> Result<(), Box<dyn std::error::Error>> {
    let dir = format!("lib/{}", package);
    // test suite
    for entry in std::fs::read_dir(&dir).unwrap() {
        let entry = entry.unwrap();
        if entry.file_type().unwrap().is_dir() {
            test_module(package, entry.file_name().to_str().unwrap())?
        }
    }
    Ok(())
}

#[tokio::main]
async fn main() -> Result<(), Box<dyn std::error::Error>> {
    match clap::App::new("cmplib")
        .about("compro-library CLI")
        .version("0.0.1")
        .subcommand(clap::App::new("snip").about("generate VSCode's snippets"))
        .subcommand(
            clap::App::new("test")
                .about("run modules' tests")
                .arg(
                    clap::Arg::with_name("package")
                        .help("test target package")
                        .takes_value(true),
                )
                .arg(
                    clap::Arg::with_name("module")
                        .help("test target module")
                        .takes_value(true),
                ),
        )
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
        ("test", Some(test_matches)) => {
            let arg_package = test_matches.value_of("package");
            let arg_module = test_matches.value_of("module");
            match (arg_package, arg_module) {
                (Some(package), Some(module)) => test_module(package, module),
                (Some(package), None) => test_package(package),
                _ => {
                    for entry in std::fs::read_dir("lib").unwrap() {
                        let entry = entry.unwrap();
                        if entry.file_type().unwrap().is_dir() {
                            test_package(entry.file_name().to_str().unwrap())?
                        }
                    }
                    Ok(())
                }
            }
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
