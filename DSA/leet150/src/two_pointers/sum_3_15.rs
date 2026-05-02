
pub struct Solution;

impl Solution {
    pub fn three_sum(nums: Vec<i32>) -> Vec<Vec<i32>> {

        let mut sorted_nums = nums.clone();
        sorted_nums.sort();
       

        println!("{:?}", nums);

        let mut result: Vec<Vec<i32>> = Vec::new();

        for (i,&n) in sorted_nums.iter().enumerate(){
            // grabbing firs itme
            
            let mut left: usize = i + 1;
            let mut right: usize = sorted_nums.len() - 1;

            if i > 0 && sorted_nums[i] == sorted_nums[i - 1] {
                    continue;  // skip duplicate
                }
            while left < right 
            {
                let sum = sorted_nums[left] + sorted_nums[right] + n;

                
                if sum == 0 {
                    result.push(vec![n, sorted_nums[left], sorted_nums[right]]);
                    left += 1;
                    right -= 1;
                    // skip duplicates
                    while left < right &&   sorted_nums[left] == 
                                            sorted_nums[left - 1] 
                    {

                        left += 1;
                    }
                    while left < right &&   sorted_nums[right] ==     
                                            sorted_nums[right + 1] 
                    {
                        right -= 1;
                    }
                }
                else if sum < 0
                {
                    left += 1;
                } 
                else 
                {
                    right -= 1;
                }
            }

        }

        result
    }
}