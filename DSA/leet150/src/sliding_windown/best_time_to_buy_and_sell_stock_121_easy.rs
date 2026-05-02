pub struct Solution;


impl Solution {
    pub fn max_profit(prices: Vec<i32>) -> i32 {
        
        // so for sliding window we have left and right
        // right alwasy moves (seeking)
        // left just moves if the condition is unsastified
        let prices_len = prices.len();
        let mut max_profit = 0;
        let mut cheapest = prices[0];

        for right in 0..prices_len{

            if prices[right] < cheapest{
                cheapest = prices[right];
            }

            let profit = prices[right] - cheapest;
            // if profit for the round is bigger then previous round
            // we advance left, the basic idea here is find which
            // combination of left and right generates the most profit
           if profit > max_profit{
                max_profit = profit;
           }

            
        }
        max_profit
    }
}