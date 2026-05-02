// use std::collections::HashMap;

//   impl Solution {
//     pub fn int_to_roman(num: i32) -> String 
//     {
//       let map: HashMap<i32,String> = HashMap::from
//       ([
//         (1, "I".to_string()),
//         (4, "IV".to_string()),
//         (5, "V".to_string()),
//         (9, "IX".to_string()),
//         (10, "X".to_string()),
//         (40, "XL".to_string()),
//         (50, "L".to_string()),
//         (90, "XC".to_string()),
//         (100, "C".to_string()),
//         (400, "CD".to_string()),
//         (500, "D".to_string()),
//         (900, "CM".to_string()),
//         (1000, "M".to_string()),
//     ]);

//     let mut num_clone = num.clone();
//     // getting last digit
//     //what is  asiystematic way of doing this we can't a
//     // so inverse patterns are jut first provided by whe nwe need 4 or 9

//     let mut roman_s = String::new();
//     while num_clone > 0 {
//       // Find the largest key less than or equal to num_clone
//       let highest = map
//         .iter()
//         .filter(|(val, _)| **val <= num_clone)
//         .max_by_key(|(val, _)| *val);

//       if let Some((highest_val, roman)) = highest {
//         num_clone -= *highest_val;
//         roman_s.push_str(roman);
//       } else {
//         break;
//       }
//     }

//     roman_s

//     }
// }
//   // Test cases
//   println!("Test 1: 3 = {}", Solution::int_to_roman(3));
//   println!("Test 2: 58 = {}", Solution::int_to_roman(58));
//   println!("Test 3: 1994 = {}", Solution::int_to_roman(1994));
