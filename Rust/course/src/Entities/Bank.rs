use crate::entities::account::BankAccount;

#[derive(Debug)]
pub struct Bank{
    accounts: Vec<BankAccount>,

}

/**
 * // Assiociated function called new() same as facoty in Java
 * like static method that we call the function, not  an instance
 * @return BankAccount
 */
 impl Bank{
    pub fn new() -> Self
    {
         Bank {accounts: vec![]}
    }

    pub fn add_account(&mut self, account: BankAccount) 
    {
        self.accounts.push(account);
    }

    pub fn total_balance(&self) -> i32
    {
        let mut total = 0;

        for account in &self.accounts 
        {
            total += account.get_balance();
        }
    
        total
    }

    /// summary of the bank (accounts)
    pub fn summary(&self) -> Vec<String>{
        self.accounts
            .iter()
            .map(|account| account.summary())
            .collect()
        }

}