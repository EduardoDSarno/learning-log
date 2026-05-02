mod program;

use program::lib::MyAccount;

fn main() {
    println!("Hello, world!");
    
    // Now you can use and debug your program module here
    // Example:
    let account = MyAccount {
        version: 1,
        authority: [0u8; 32],
        is_initalized: false,
        score: 0,
    };
    
    println!("Debug account: {:?}", account);
}
