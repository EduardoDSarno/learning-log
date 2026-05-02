use std::net::TcpStream;
use std::io::prelude::*;
use crate::response::response;

use crate::http::Http;

pub fn handle_client(mut stream: TcpStream)
{
    // buffer is where we allocate the memory temporarily
    // in this case set to always starts at 0 and go to 1024
    let mut buffer = [0; 1024];

    
    match stream.read(&mut buffer) 
    {
        Ok(bytes_read) => 
        {
            let bytes = &buffer[..bytes_read];
            let s = std::str::from_utf8(bytes).unwrap();
            parse_http(s);
            stream.write_all(response().as_bytes());

            
        }
        Err(e) => 
        {
            eprintln!("Failed to read from stream: {}", e);
        }
    }

    // starting hyper text trasmission protocol

}

fn parse_http(content_str: &str){
     
    let lines:Vec<&str> = content_str.lines().collect();

    let request_line = lines.first().unwrap();
    let req_lines: Vec<&str> = request_line.split(' ').collect();

    println!("{:?}", req_lines);
    // for line in lines{
    //     println!("{:?}", line)
    // }

    let http = Http::new(
        req_lines[0].to_string(), // "GET" 
        req_lines[1].to_string(), // "/" → path
        req_lines[2].replace("HTTP/", "").parse().unwrap_or(1.1), // version or defoult
    );

    println!("{:?}", http);
}
