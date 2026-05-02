// fn main() {
//     struct Solution {}

//     impl Solution {
//         pub fn longest_common_prefix(strs: Vec<String>) -> String {
//             // Handle empty input
//             if strs.is_empty() {
//                 return String::new();
//             }

//             // first word
//             let first = strs[0].as_bytes();

//             for letter in 0..first.len(){
//                 // for each letter
//                 let letter_index = first[letter];

//                 for word in &strs[1..]
//                 {
//                     let other_bytes = word.as_bytes();
//                     if letter >= other_bytes.len() || other_bytes[letter] != letter_index {
//                         return strs[0][..letter].to_string();
//                     }
//                 }
//             }

//             println!("{}", strs[0]);
//             strs[0].clone()

//         }

//     }

//     // Test it
//     let test = vec![
//         "flower".to_string(),
//         "flow".to_string(),
//         "flight".to_string(),
//     ];
//     let result = Solution::longest_common_prefix(test);
//     println!("Prefix: {}", result); // Should print
// }