use itertools::Itertools;

#[derive(serde::Serialize)]
struct Snippet {
    name: String,
    prefix: String,
    description: String,
    body: Vec<String>,
}

fn main() {
    let src = std::fs::read_to_string("a.cpp").unwrap();
    let res = std::fs::write(
        "cpp.json",
        serde_json::to_string_pretty(&Snippet {
            name: "test".to_string(),
            prefix: "tst".to_string(),
            description: "first snippet".to_string(),
            body: regex::Regex::new(r"var_(\w+)")
                .unwrap()
                .captures_iter(&src)
                .map(|cap| (cap[0].to_string(), cap[1].to_string()))
                .unique()
                .enumerate()
                .collect::<std::collections::HashMap<_, _>>()
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
        })
        .unwrap(),
    );
    if res.is_err() {
        panic!("error");
    }
}
