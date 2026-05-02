mod http;
mod handler;
mod response;

use std::net::TcpListener;

use handler::handle_client;

fn main()
{
    let listner: TcpListener = TcpListener::bind("127.0.0.1:8081").unwrap();

    // loop to wait for connection
    for stream in listner.incoming(){
        // we match if it is OK we handle the strem
        match stream 
        {
            Ok(stream) =>
            {
                handle_client(stream);
                
            }
            Err(e) => {panic!("{}", e)}
        }
    }
}
