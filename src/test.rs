pub fn test(
    arg_package: Option<&str>,
    arg_module: Option<&str>,
) -> Result<(), Box<dyn std::error::Error>> {
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
    for entry in std::fs::read_dir(&dir).unwrap() {
        let entry = entry.unwrap();
        if entry.file_type().unwrap().is_dir() {
            test_module(package, entry.file_name().to_str().unwrap())?
        }
    }
    Ok(())
}
