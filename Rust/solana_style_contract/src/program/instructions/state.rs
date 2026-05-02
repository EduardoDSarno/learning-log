
use solana_program::pubkey::Pubkey;
use borsh::{BorshSerialize, BorshDeserialize};

#[derive(BorshSerialize, BorshDeserialize)]
pub struct State {
    pub is_initialized: bool,
    pub authority: Pubkey,
    pub score: u64,
    pub approved: bool,
}

impl State {
    pub const LEN: usize = 42; //  1 + 32 + 8 + (1)

    pub fn new(is_initialized: bool, authority: Pubkey, score: u64) -> Self {
        State { is_initialized, authority, score, approved: false }
    }
}