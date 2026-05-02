// use std::vec;

// fn main() {
//     struct Solution {}

//     impl Solution {
//         pub fn is_valid(s: String) -> bool {
//             let mut stack: Vec<char> = vec![];
//             let opening = vec!['(', '{', '['];
//             let closing = vec![')', '}', ']'];

//             for c in s.chars() {
//                 // Opening  push to stack
//                 if opening.contains(&c) {
//                     stack.push(c);
//                 }
//                 // Closing bracketcheck if it matches the last opening
//                 else if closing.contains(&c) {
//                     if stack.is_empty() {
//                         return false;
//                     }
//                     let last = stack.pop().unwrap();
//                     if (c == ')' && last != '(')
//                         || (c == '}' && last != '{')
//                         || (c == ']' && last != '[')
//                     {
//                         return false;
//                     }
//                 }
//             }

//             // Stack hjas be empty for all brackets to be matched
//             stack.is_empty()
//         }
//     }
// }