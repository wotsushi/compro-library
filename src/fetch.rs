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
pub async fn fetch_testcase_from_aoj(
    id: &str,
    package: &str,
    module: &str,
) -> Result<(), Box<dyn std::error::Error>> {
    let header_info = reqwest::get(&format!(
        "https://judgedat.u-aizu.ac.jp/testcases/{}/header",
        id
    ))
    .await?
    .json::<AOJHeaderInfo>()
    .await?;
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
        if !testcase.input.contains("terminated") && !testcase.output.contains("terminated") {
            std::fs::write(format!("{}/in/{}", dir, header.serial), &testcase.input)?;
            std::fs::write(format!("{}/out/{}", dir, header.serial), &testcase.output)?;
        }
    }
    Ok(())
}
