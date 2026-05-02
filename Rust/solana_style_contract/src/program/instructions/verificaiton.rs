use solana_program::{
    account_info::{AccountInfo, next_account_info}, program_error::ProgramError, pubkey::Pubkey
};
use borsh::BorshDeserialize;
use super::state::State;


pub struct VerifiedAccounts<'a> {
    pub signer: &'a AccountInfo<'a>,
    pub state_account: &'a AccountInfo<'a>,
    pub state_data: State,
}

pub fn verify<'a>(
    accounts: &'a [AccountInfo<'a>], 
    program_id: &Pubkey
) -> Result<VerifiedAccounts<'a>, ProgramError> {
    let accounts_iter = &mut accounts.iter();
    
    let signer = next_account_info(accounts_iter)?;
    let state = next_account_info(accounts_iter)?;
    // All your verification checks...
    if !signer.is_signer {
        return Err(ProgramError::MissingRequiredSignature);
    }
    
    if state.owner != program_id {
        return Err(ProgramError::IncorrectProgramId);
    }
    
    if !state.is_writable {
        return Err(ProgramError::InvalidAccountData);
    }
    
    if state.data_len() != State::LEN {
        return Err(ProgramError::InvalidAccountData);
    }
    
    // Parse the existing state data
    let state_data = State::try_from_slice(&state.data.borrow())?;
    
    Ok(VerifiedAccounts {
        signer,
        state_account: state,
        state_data,
    })
}