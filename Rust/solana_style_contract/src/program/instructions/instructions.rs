use solana_program::program_error::ProgramError;

// A instruction is valid when 1. Changes the account data 2. check permissions or updates states

pub enum ProgramInstruction{

    Initialize,
    Add { amount: u64 },
    Subtract { amount: u64 },
    Approve,    
}

impl ProgramInstruction{
    pub fn unpack(instruction_data: &[u8]) ->Result<Self,ProgramError>
    {
        let instruction = instruction_data
                          .get(0)
                          .ok_or(
                            ProgramError::InvalidInstructionData
                          )?;

        match instruction 
        {
            0 => Ok(Self::Initialize),
            1 => {
                let amount = Self::unpack_amount(instruction_data.get(1..).ok_or(
                    ProgramError::InvalidInstructionData
                )?)?;
                Ok(Self::Add { amount })
            },
            2 => {
                let amount = Self::unpack_amount(instruction_data.get(1..).ok_or(
                    ProgramError::InvalidInstructionData
                )?)?;
                Ok(Self::Subtract { amount })
            },
            3 => Ok(Self::Approve),
            _ => Err(ProgramError::InvalidInstructionData),
        }                  
    }

    fn unpack_amount(input: &[u8]) -> Result<u64, ProgramError> {
        if input.len() < 8 {
            return Err(ProgramError::InvalidInstructionData);
        }

        let amount_bytes: [u8; 8] = input[0..8]
            .try_into()
            .map_err(|_| ProgramError::InvalidInstructionData)?;

        Ok(u64::from_le_bytes(amount_bytes))
    }

}