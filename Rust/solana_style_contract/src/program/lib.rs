use super::instructions::instructions::ProgramInstruction;
use super::instructions::instructions_logic::*;

use borsh::{BorshDeserialize, BorshSerialize};
use solana_program::{
    account_info::{next_account_info, AccountInfo},
    entrypoint,
    entrypoint::ProgramResult,
    program_error::ProgramError,
    pubkey::Pubkey,
};

#[derive(BorshDeserialize, BorshSerialize, Debug)]
pub struct MyAccount {
    // for account type and future upgrades
    pub version: u8,
    pub authority: [u8; 32], // pubkey bytes
    pub is_initalized: bool,
    pub score: u64,
}


#[cfg(not(feature = "exclude_entrypoint"))]
entrypoint!(process_instruction);

pub fn process_instruction<'a>(
    program_id: &Pubkey,
                            accounts: &'a [AccountInfo<'a>],
                            instruction_data: &[u8],
                        ) -> ProgramResult 
{
    let accounts_iter = &mut accounts.iter();
    let account = next_account_info(accounts_iter)?;

    if account.owner != program_id {
        return Err(ProgramError::IncorrectProgramId);
    }

    let instruction = ProgramInstruction::unpack(instruction_data)?;

    match instruction 
    {
        ProgramInstruction::Initialize => initialize(accounts, program_id),
        ProgramInstruction::Add { amount } => add(accounts, program_id, amount),
        ProgramInstruction::Subtract { amount } => subtract(accounts, program_id, amount),
        ProgramInstruction::Approve => approve(accounts, program_id),
    }
}

