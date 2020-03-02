#[derive(serde::Serialize)]
struct Snippet {
    name: String,
    prefix: String,
    description: String,
    body: Vec<String>,
}

fn main() {
    let res = std::fs::write(
        "cpp.json",
        serde_json::to_string_pretty(&Snippet {
            name: "test".to_string(),
            prefix: "tst".to_string(),
            description: "first snippet".to_string(),
            body: std::fs::read_to_string("a.cpp")
                .unwrap()
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
