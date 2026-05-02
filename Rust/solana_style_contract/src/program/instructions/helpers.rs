use borsh::BorshSerialize;
use solana_program::{
    account_info::AccountInfo, entrypoint::ProgramResult, program_error::ProgramError, pubkey::Pubkey
};

use super::state::State;

pub fn require_authority(state: &State, signer: &Pubkey) -> ProgramResult {
    if signer != &state.authority {
        return Err(ProgramError::IllegalOwner);
    }
    Ok(())
}

pub fn require_initialized(state: &State) -> ProgramResult {
    if !state.is_initialized {
        return Err(ProgramError::UninitializedAccount);
    }
    Ok(())
}

pub fn require_uninitialized(state: &State) -> ProgramResult {
    if state.is_initialized {
        return Err(ProgramError::AccountAlreadyInitialized);
    }
    Ok(())
}

pub fn write_state(state: &State, account: &AccountInfo) -> ProgramResult {
    state.serialize(&mut &mut account.data.borrow_mut()[..])?;
    Ok(())
}
