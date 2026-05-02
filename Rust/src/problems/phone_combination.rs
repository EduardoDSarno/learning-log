  
//   impl Solution {
//     pub fn letter_combinations(digits: String) -> Vec<String> {
//         // Map phone digits to their corresponding letters
//         let phone_map: HashMap<char, Vec<char>> = HashMap::from([
//             ('2', vec!['a', 'b', 'c']),
//             ('3', vec!['d', 'e', 'f']),
//             ('4', vec!['g', 'h', 'i']),
//             ('5', vec!['j', 'k', 'l']),
//             ('6', vec!['m', 'n', 'o']),
//             ('7', vec!['p', 'q', 'r', 's']),
//             ('8', vec!['t', 'u', 'v']),
//             ('9', vec!['w', 'x', 'y', 'z']),
//         ]);

//         // getting vec from digits
//         let digits_vec: Vec<char> = digits.chars().collect();
//         let mut letters_vec: Vec<Vec<char>> = vec![];

//         // For each digit get its the letters from phone_map
//         for digit in digits_vec {
//             if let Some(letters) = phone_map.get(&digit) {
//                 letters_vec.push(letters.clone());
//             }
//         } 

//         // Handle empty input
//         if letters_vec.is_empty() {
//             return vec![];
//         }

//         // Start with one empty string
//         let mut result: Vec<String> = vec!["".to_string()];

//         // For each vector of letters, combine with existing results
//         for letter_vec in &letters_vec {
//             let mut new_result : Vec<String> = Vec::new();

//             for letter in &result{
                
//                 for chr in letter_vec{
//                     let mut new_comb = letter.clone();
//                     new_comb.push(*chr);
//                     new_result.push(new_comb);
                    
//                 }
//             }
//             //println!("{:?}", new_result);
//             result = new_result;
//         }
//         //println!("{:?}", result);
//         result
//     }
// }

// let sol = Solution::letter_combinations("234".to_string());