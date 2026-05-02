use std::fs;

pub fn response() -> String 
{
    let file_path = "static/index.html";
    let content = fs::read_to_string(file_path).unwrap();
    
    // HTTP Response structure:
    // 1. Status line
    // 2. Headers
    // 3. Empty line (separates headers from body)
    // 4. Body (the file content)
    
    let response = format!(
        "HTTP/1.1 200 OK\r\nContent-Length: {}\r\nContent-Type: text/html\r\n\r\n{}",
        content.len(),
        content
    );

    response
}