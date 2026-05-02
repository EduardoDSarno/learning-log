
use super::media_type::Media;

impl Media 
{
    #[warn(dead_code)]
    fn _description(&self) -> String
    {
        match self {
            Media::Book { title, author } =>{
                format!("Book: {} written by {}", title,author)
            }
            Media::Audiobook { title } =>{
                format!("Audiobook: {} ", title)
            }
            Media::Movie { title, director } =>{
                format!("Movie: {} directed by {}", title, director)
            }
            
        }
    }    
}