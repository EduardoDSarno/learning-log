use std::collections::{HashSet, hash_set};

pub struct Solution;

impl Solution {
    pub fn length_of_longest_substring(s: String) -> i32 {
        
        let length: usize = s.len(); 
       // println!("lenght {:#}\n", length);
        let strr: Vec<char> = s.chars().collect();

        if length <= 1 {
            return length as i32;
        }

        let mut left: usize = 0;
        let mut max_window_size: usize = 0;

        let mut set: HashSet<char> = HashSet::new();

        for right in 0..length {

            let mut window_size: usize = 0;
            
            if !set.contains(&strr[right])
            {
                set.insert(strr[right]);
            }
            else // if they are the same
            {
                // then move left left until reach new window (find duplicate)
                while strr[left] != strr[right] && left < right {
                    set.remove(&strr[left]);
                    left += 1;
                }
                set.remove(&strr[left]);
                left += 1;

                set.insert(strr[right]);
            }
            window_size = right - left + 1; // for inclusive
            
            println!("left {:#}",  left);               
            println!("right {:#}", right);

            // slice   
            let sub: &[char] = &strr[left..right];
            println!("string {:?}", sub);
            // we want to check count
            if window_size > max_window_size 
            {
                max_window_size = window_size
            }    
        }

        max_window_size as i32
    }
}