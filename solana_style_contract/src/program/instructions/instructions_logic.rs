use super::state::State;
use solana_program::{
    account_info::AccountInfo, entrypoint::ProgramResult, program_error::ProgramError, pubkey::Pubkey
};

use crate::program::instructions::helpers::{
    require_authority, require_initialized, require_uninitialized, write_state,
};
use crate::program::instructions::verificaiton::verify;

// Handler functions
pub fn initialize<'a>(accounts: &'a [AccountInfo<'a>], program_id: &Pubkey) -> ProgramResult 
{
    // using verified to make code clean and simpler
    let verified = verify(accounts, program_id)?;

    require_uninitialized(&verified.state_data)?;

    // Create new initialized state with required fields
    let new_state = State::new(true, *verified.signer.key, 0);

    // Serialize to account
    write_state(&new_state, verified.state_account)?;
    
    Ok(())
}

pub fn add<'a>(accounts: &'a [AccountInfo<'a>], program_id: &Pubkey, amount: u64) -> ProgramResult 
{
    // using verified to make code clean and simpler
    let mut verified = verify(accounts, program_id)?;

    require_initialized(&verified.state_data)?;
    require_authority(&verified.state_data, verified.signer.key)?;

    verified.state_data.score = verified.state_data.score
    .checked_add(amount)
    .ok_or(ProgramError::InvalidInstructionData)?;

    write_state(&verified.state_data, verified.state_account)?;

    Ok(())
}

pub fn subtract<'a>(accounts: &'a [AccountInfo<'a>], program_id: &Pubkey, amount: u64) -> ProgramResult {

     // using verified to make code clean and simpler
     let mut verified = verify(accounts, program_id)?;

     require_initialized(&verified.state_data)?;
     require_authority(&verified.state_data, verified.signer.key)?;
    verified.state_data.score = verified.state_data.score
    .checked_sub(amount)
    .ok_or(ProgramError::InvalidInstructionData)?;
 
     write_state(&verified.state_data, verified.state_account)?;
 
     Ok(())
}

pub fn approve<'a>(accounts: &'a [AccountInfo<'a>], program_id: &Pubkey) -> ProgramResult {
    let mut verified = verify(accounts, program_id)?;

    require_initialized(&verified.state_data)?;
    require_authority(&verified.state_data, verified.signer.key)?;
    // if already approved 
    if verified.state_data.approved {
        return Err(ProgramError::InvalidAccountData);
    }

    verified.state_data.approved = true;
    write_state(&verified.state_data, verified.state_account)?;

    Ok(())
}
