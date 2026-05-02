#[derive(Debug)]
pub struct BankAccount{
    id: u32,
    balance: i32,
    holder: String,
}


/// #Bank Account
/// 
impl BankAccount{
    pub fn new(id: u32, holder: String) -> Self
    {
        BankAccount 
        {
            id,
            holder,
            balance: 0
        }
    }

    /// getter for balance
    pub fn get_balance(&self) -> i32 {
        self.balance
    }
    /// Deposits into the Accouunt, Amound USd will be added to account.balance
    pub fn deposit(&mut self,amountUSD: i32 ) -> i32
    {
        self.balance += amountUSD;
        self.balance
    }

    /// Withdraw from the Accouunt, Amound USd will be added to account.balance
    pub fn withdraw(&mut self, amountUSD: i32) -> i32
    {
        self.balance -= amountUSD;
        self.balance
    }

    /// format account into String
    pub fn summary(&self) -> String
    {
        format!("{} has a balance of {}", self.holder, self.balance)
    }
}