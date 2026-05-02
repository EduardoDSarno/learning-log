use crate::media::catalog::{Catalog};
use crate::media::media_type::Media;


mod media;


fn main() {
    println!("Hello, world!");
    let movie = Media::Movie{title: "The Dark Knight".to_string(), director: "Christopher Nolan".to_string()};
    let book = Media::Book{title: "The Great Gatsby".to_string(), author: "F. Scott Fitzgerald".to_string()};
    let audiobook = Media::Audiobook{title: "The Hitchhiker's Guide to the Galaxy".to_string()};
    let mut catalog = Catalog::new();

    catalog.add(movie);
    catalog.add(book);
    catalog.add(audiobook);

    let item = catalog.get_by_index(10);

    //catalog.print_catalog();
    println!("{:#?}", item)
}
