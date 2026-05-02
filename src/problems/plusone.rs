// impl Solution {
//     pub fn plus_one(digits: Vec<i32>) -> Vec<i32> {
//         let mut digits = digits;
        
//         for i in (0..digits.len()).rev() {
//             if digits[i] < 9 {
//                 digits[i] += 1;
//                 return digits;
//             }
//             digits[i] = 0;
//         }
        
//         // All digits were 9 (e.g., [9,9,9] -> [1,0,0,0])
//         let mut result = vec![1];
//         result.append(&mut digits);
//         result
//     }
// }