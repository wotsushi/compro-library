mod fetch;
mod snip;
mod test;

fn main() -> Result<(), Box<dyn std::error::Error>> {
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
        ("snip", _) => snip::write_snippet(),
        ("test", Some(test_matches)) => test::test(
            test_matches.value_of("package"),
            test_matches.value_of("module"),
        ),
        ("fetch", Some(fetch_matches)) => fetch::fetch_and_write_testcase_from_aoj(
            fetch_matches.value_of("id").unwrap(),
            fetch_matches.value_of("package").unwrap(),
            fetch_matches.value_of("module").unwrap(),
        ),
        _ => Ok(()),
    }
}
