mod Basket;
mod stack;
mod conteiner;

use stack::Stack;
use basket::Basket;
use conteiner::Conteiner;

fn add_string<T: Conteiner::<String>>(a: &mut T, b: String){
    a.put(b)
}
fn main() {
    println!("Hello, world!");
}
