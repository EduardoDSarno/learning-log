// use core::num;

// fn main ()
// {
//   struct Solution{};

//   impl Solution {
//     pub fn remove_duplicates(nums: &mut Vec<i32>) -> i32 
//     {
//       if nums.is_empty() {
//           return 0;
//       }
      
//       let mut write_index = 1;
      
//       for read_index in 1..nums.len() {
//           if nums[read_index] != nums[write_index - 1] {
//               nums[write_index] = nums[read_index];
//               write_index += 1;
//           }
//       }
      
//       write_index as i32
//     }
//   }


//   let solution = Solution{};

// let mut test_nums = vec![0, 0, 1, 1, 1, 2, 2, 3, 3, 4];
// let result = Solution::remove_duplicates(&mut test_nums);
// let result_array = &test_nums[0..result as usize];
// println!("Result: {}", result);
// println!("final Array: {:?}", result_array);
// println!("First {} elements: {:?}", result, result_array);
// }