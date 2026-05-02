use serde::Serialize;

#[derive(Debug, Serialize)]

pub enum Media
{
    Book{title:String, author:String},
    Movie{title: String, director:String},
    Audiobook{title:String}
}