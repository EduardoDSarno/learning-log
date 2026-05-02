// pub struct Solution;

// impl Solution {
//     pub fn int_to_roman(num: i32) -> String {
//         // Sorted array in descending order - iterate once, no repeated scans!
//         // This is MUCH faster than HashMap because:
//         // 1. Single pass through array (O(n) where n=13)
//         // 2. No hash computation overhead
//         // 3. Better cache locality
//         // 4. No repeated scans on each iteration
//         let values = [
//             (1000, "M"),
//             (900, "CM"),
//             (500, "D"),
//             (400, "CD"),
//             (100, "C"),
//             (90, "XC"),
//             (50, "L"),
//             (40, "XL"),
//             (10, "X"),
//             (9, "IX"),
//             (5, "V"),
//             (4, "IV"),
//             (1, "I"),
//         ];

//         let mut num = num;
//         let mut roman = String::new();

//         // Single pass through the array - O(n) where n=13, not O(k*n)!
//         // For 1994: only 13 comparisons total, not 52+ like the HashMap version
//         for (value, symbol) in values.iter() {
//             // How many times does this value fit?
//             let count = num / value;
//             if count > 0 {
//                 // Append the symbol that many times
//                 for _ in 0..count {
//                     roman.push_str(symbol);
//                 }
//                 // Subtract what we've used using modulo (more efficient)
//                 num %= value;
//             }
//         }

//         roman
//     }
// }

// // Test cases
// fn main() {
//     println!("Test 1: 3 = {}", Solution::int_to_roman(3));
//     println!("Test 2: 58 = {}", Solution::int_to_roman(58));
//     println!("Test 3: 1994 = {}", Solution::int_to_roman(1994));
// }
