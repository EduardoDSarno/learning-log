mod entities;  // mod declaration

use entities::account::BankAccount;
use entities::bank::Bank;

fn main() {
    let mut bank = Bank::new();
    let account = BankAccount::new(1, String::from("me"));
    
    
    bank.add_account(account);
}








