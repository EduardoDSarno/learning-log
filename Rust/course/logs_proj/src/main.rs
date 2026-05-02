use std::fs;

fn extract_error(log_txt: &str) -> Vec<&str>
{
    let lines: Vec<&str> = log_txt.lines().collect();

    let mut result: Vec<&str> = vec![];

    for line in lines {
        if line.starts_with("ERROR") {
            result.push(line);
        }
    }
    result
}


fn main() 
{

    let text = fs::read_to_string("src/logs.txt")
                                  .expect("failed to read logs.txt");

    let error_logs = extract_error(text.as_str());

    // not assigning any variable here because fs::write returst Result<(), Err?>
    fs::write("src/errors.txt", error_logs.join("\n"))
                                                          .expect("failed to write errors.txt");

                                                          

    // match fs::read_to_string("src/logs.txt") 
    // {
    //     Ok(success_txt) => 
    //     {
    //         let error_logs = extract_error(&success_txt);
    
    //         match fs::write("errors.txt", error_logs.join("\n"))
    //         {
    //             Ok(_) => println!("Wrote on errors.txt"),
    //             Err(reason) => println!("Failed {:#?}", reason),
    //         }

    //     }
    //     Err(error) => println!("Failed {:?}", error),
    // }

}