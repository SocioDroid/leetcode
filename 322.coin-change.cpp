/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 *
 * https://leetcode.com/problems/coin-change/description/
 *
 * algorithms
 * Medium (37.88%)
 * Likes:    6947
 * Dislikes: 195
 * Total Accepted:    648.2K
 * Total Submissions: 1.7M
 * Testcase Example:  '[1,2,5]\n11'
 *
 * You are given an integer array coins representing coins of different
 * denominations and an integer amount representing a total amount of money.
 * 
 * Return the fewest number of coins that you need to make up that amount. If
 * that amount of money cannot be made up by any combination of the coins,
 * return -1.
 * 
 * You may assume that you have an infinite number of each kind of coin.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: coins = [1,2,5], amount = 11
 * Output: 3
 * Explanation: 11 = 5 + 5 + 1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: coins = [2], amount = 3
 * Output: -1
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: coins = [1], amount = 0
 * Output: 0
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: coins = [1], amount = 1
 * Output: 1
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: coins = [1], amount = 2
 * Output: 2
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= coins.length <= 12
 * 1 <= coins[i] <= 2^31 - 1
 * 0 <= amount <= 10^4
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // sort(coins.begin(), coins.end());
        
        vector<int> dp(amount+1, amount+1);
        
        dp[0] = 0;
        for(int j = 0;j<coins.size(); j++){
            
            // int count = 0;
            for(int i = coins[j];i <amount+1; i++){
                // if(coins[j]>i)
                //     continue;
                dp[i] = min(1+dp[i-coins[j]],dp[i]);
            }
            
        }
        
        // for(auto i:dp)
        //     cout<<i<<" "<<endl;
        return dp[dp.size()-1]==amount+1? -1 : dp[dp.size()-1];
    }
};
// @lc code=end

