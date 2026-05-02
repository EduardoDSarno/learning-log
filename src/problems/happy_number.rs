// use std::vec;

// fn main(){
//   struct  Solution{};

//   impl Solution {
//     pub fn is_happy(mut n: i32) -> bool {
      
//       use std::collections::HashSet;
//       if n == 1{
//         return true;
//       }
      
//       let mut seen: HashSet<i32> = HashSet::new();

      
//       while n != 1
//       {
       
//         if seen.contains(&n) 
//         {
//           return false;
//         }
//         seen.insert(n);
      
//         let mut sum = 0;
        
//         while n != 0 
//         {
         
//           let reminder = n % 10;
//           let expo= reminder.pow(2);
//           sum += expo;
//           n = n / 10;
//           println!("{}", sum)
//         }
//         n = sum;
//       }
     
//       true
      
//     }
// }

// let test = 19;

// let result = Solution::is_happy(19);
// println!("{}", result)
// }