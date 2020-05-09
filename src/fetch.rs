pub fn fetch_and_write_testcase_from_aoj(
    id: &str,
    package: &str,
    module: &str,
) -> Result<(), Box<dyn std::error::Error>> {
    let (dir_in, dir_out, inputs, outputs) = fetch_testcase_from_aoj(
        id,
        package,
        module,
        |url| match reqwest::blocking::get(url) {
            reqwest::Result::Ok(response) => match response.json() {
                reqwest::Result::Ok(header_info) => Ok(header_info),
                reqwest::Result::Err(e) => Err(Box::new(e)),
            },
            reqwest::Result::Err(e) => Err(Box::new(e)),
        },
        |url| match reqwest::blocking::get(url) {
            reqwest::Result::Ok(response) => match response.text() {
                reqwest::Result::Ok(testcase) => Ok(testcase),
                reqwest::Result::Err(e) => Err(Box::new(e)),
            },
            reqwest::Result::Err(e) => Err(Box::new(e)),
        },
    )?;
    std::fs::create_dir_all(dir_in)?;
    std::fs::create_dir_all(dir_out)?;
    for (dest, input) in inputs {
        std::fs::write(dest, input)?;
    }
    for (dest, output) in outputs {
        std::fs::write(dest, output)?;
    }
    Ok(())
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

fn fetch_testcase_from_aoj<F, G>(
    id: &str,
    package: &str,
    module: &str,
    get_header: F,
    get_testcase: G,
) -> Result<
    (String, String, Vec<(String, String)>, Vec<(String, String)>),
    Box<dyn std::error::Error>,
>
where
    F: Fn(&str) -> Result<AOJHeaderInfo, Box<dyn std::error::Error>>,
    G: Fn(&str) -> Result<String, Box<dyn std::error::Error>>,
{
    let header_info = get_header(&format!(
        "https://judgedat.u-aizu.ac.jp/testcases/{}/header",
        id
    ))?;
    let dir = format!("content/{}/{}/{}", package, module, id);
    let mut inputs = vec![];
    let mut outputs = vec![];
    for header in header_info.headers {
        inputs.push((
            format!("{}/in/{:03}", dir, header.serial),
            get_testcase(&format!(
                "https://judgedat.u-aizu.ac.jp/testcases/{}/{}/in",
                id, header.serial
            ))?,
        ));
        outputs.push((
            format!("{}/out/{:03}", dir, header.serial),
            get_testcase(&format!(
                "https://judgedat.u-aizu.ac.jp/testcases/{}/{}/out",
                id, header.serial
            ))?,
        ));
    }
    Ok((
        format!("{}/in", dir),
        format!("{}/out", dir),
        inputs,
        outputs,
    ))
}

#[test]
fn test_generate_snippet() {
    fn get_header(url: &str) -> Result<AOJHeaderInfo, Box<dyn std::error::Error>> {
        match url {
            "https://judgedat.u-aizu.ac.jp/testcases/DPL_5_D/header" => Ok(AOJHeaderInfo {
                problem_id: "DPL_5_D".to_string(),
                headers: vec![
                    AOJHeader {
                        serial: 1,
                        name: "00_small__00.in".to_string(),
                        input_size: 77,
                        output_size: 16,
                        score: -1,
                    },
                    AOJHeader {
                        serial: 2,
                        name: "01_rand__00.in".to_string(),
                        input_size: 186,
                        output_size: 28,
                        score: -1,
                    },
                ],
            }),
            _ => Err(Box::new(simple_error::SimpleError::new(format!(
                "invalid URL: {}",
                url
            )))),
        }
    }
    fn get_testcase(url: &str) -> Result<String, Box<dyn std::error::Error>> {
        match url {
            "https://judgedat.u-aizu.ac.jp/testcases/DPL_5_D/1/in" => {
                Ok("1 2\n3 4 5\n".to_string())
            }
            "https://judgedat.u-aizu.ac.jp/testcases/DPL_5_D/1/out" => Ok("6\n7\n".to_string()),
            "https://judgedat.u-aizu.ac.jp/testcases/DPL_5_D/2/in" => Ok("0\n".to_string()),
            "https://judgedat.u-aizu.ac.jp/testcases/DPL_5_D/2/out" => Ok("0\n".to_string()),
            _ => Err(Box::new(simple_error::SimpleError::new(format!(
                "invalid URL: {}",
                url
            )))),
        }
    }
    let actual =
        fetch_testcase_from_aoj("DPL_5_D", "struct", "mint", get_header, get_testcase).unwrap();
    let expected = (
        "content/struct/mint/DPL_5_D/in".to_string(),
        "content/struct/mint/DPL_5_D/out".to_string(),
        vec![
            (
                "content/struct/mint/DPL_5_D/in/001".to_string(),
                "1 2\n3 4 5\n".to_string(),
            ),
            (
                "content/struct/mint/DPL_5_D/in/002".to_string(),
                "0\n".to_string(),
            ),
        ],
        vec![
            (
                "content/struct/mint/DPL_5_D/out/001".to_string(),
                "6\n7\n".to_string(),
            ),
            (
                "content/struct/mint/DPL_5_D/out/002".to_string(),
                "0\n".to_string(),
            ),
        ],
    );
    assert_eq!(expected, actual);
}
