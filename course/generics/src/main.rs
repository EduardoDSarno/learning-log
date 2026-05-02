use core::num;

use num_traits::{Float, ToPrimitive}; // add method to 


fn solve<T:Float>(num1: T, num2 : T) -> T
{
    num1.powi(2) + num2.powi(2).sqrt()
}
fn main() {
    println!("Hello, world!");

    let a = 3.0;
    let b = 4.0;

    solve(a, b);
}
