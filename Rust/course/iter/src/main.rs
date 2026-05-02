




use std::iter::Iterator;

fn print_elements<T: std::fmt::Debug>(elements: Vec<T>) {
    // let mut element_iter = element.iter();

    // // saying while there is some element on iter.next we print
    // while let Some(element) = element_iter.next() {
    //     println!("{:#?}", element);
    // }

    elements.iter().for_each(|el| println!("{:?}", el));
}

fn to_uppercase (list: &[String]) -> Vec<String>
{
    list.iter()
    .map(|l| l.to_uppercase())
    .collect()
}
fn  trucate_to_one(list: &mut [String])
{
    list.iter_mut().for_each(|e| e.truncate(1));
}

fn move_vec(list: Vec<String>) -> Vec<String>
{
    list.into_iter().map(|l| l.to_uppercase()).collect()
}

fn find_color_or_default(list: &[String], color: &str, fallback: &str) -> String
{
    list.iter()
        .find(|l| l.to_lowercase() == color.to_lowercase())
        .unwrap_or(&fallback.to_string())
        .to_string()
}


fn main() {
    let mut colors:Vec<String> = vec![
    "red".to_string(), 
    "green".to_string(), 
    "blue".to_string(), 
    "yellow".to_string()]; // to_string is used to convert the string to a String


    //trucate_to_one(&mut colors); // &mut is used to modify the list in place
   // print_elements(colors);

   let uppercase = to_uppercase(&colors);

   println!("{:#?}", uppercase)

}
