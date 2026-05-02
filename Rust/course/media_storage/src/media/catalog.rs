use super::media_type::Media;
use serde::Serialize;
use serde_json::value;

#[derive(Debug, Serialize)]
pub struct Catalog {
    items: Vec<Media>,
}


impl Catalog {
    pub fn new() -> Self{
        Catalog { items: vec![] }
    }
    pub fn add(&mut self, media: Media)
    {
        self.items.push(media);
    }

    pub fn print_catalog(&self)
    {
        let v = serde_json::to_string_pretty(self).unwrap();
        println!("{}", v)
    }

    pub fn get_by_index(&self, index: usize) -> Option<&Media>
    {
        // we dont wanna use self.items[index] because it will return a value and move it out of the Vec
        // we want to use a REFERENCE, because is read only.

        match self.items.get(index) 
        {
            Some(v) => 
            {
                println!("Found item");
                Some(v)
            }
            None => 
            {
                println!("Item not found");
                None
            }
        }
        
        // if index < self.items.len(){
        //     Some(&self.items[index])
        // }
        // else{
        //     println!("The size of the catalog is {} items, choose a value smaller than this", self.items.len() -1);
        //     None
        // }

    }
}