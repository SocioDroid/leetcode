/*
 * @lc app=leetcode id=64 lang=cpp
 *
 * [64] Minimum Path Sum
 *
 * https://leetcode.com/problems/minimum-path-sum/description/
 *
 * algorithms
 * Medium (56.68%)
 * Likes:    4735
 * Dislikes: 85
 * Total Accepted:    541.4K
 * Total Submissions: 953.7K
 * Testcase Example:  '[[1,3,1],[1,5,1],[4,2,1]]'
 *
 * Given a m x n grid filled with non-negative numbers, find a path from top
 * left to bottom right, which minimizes the sum of all numbers along its
 * path.
 * 
 * Note: You can only move either down or right at any point in time.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
 * Output: 7
 * Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: grid = [[1,2,3],[4,5,6]]
 * Output: 12
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == grid.length
 * n == grid[i].length
 * 1 <= m, n <= 200
 * 0 <= grid[i][j] <= 100
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int minsum = INT_MAX;
    void solve(vector<vector<int>>& grid, vector<vector<int>>& dp ){
        for(int i =0 ; i<grid.size(); i++){
            for(int j =0 ; j<grid[0].size(); j++){
                if(i==0 && j ==0)
                    dp[i][j]  = grid[i][j];
                else if(i==0)
                    dp[i][j] = grid[i][j]+dp[i][j-1];
                else if(j==0)
                    dp[i][j] = grid[i][j]+dp[i-1][j];
                else
                    dp[i][j] = grid[i][j]+min(dp[i-1][j], dp[i][j-1]);                                                    
            }           
        }
    }    
    
    int minPathSum(vector<vector<int>>& grid) {
        int sum = 0;
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), INT_MAX));
        solve(grid, dp);
        return dp[grid.size()-1][grid[0].size()-1];        
    }
};
// @lc code=end

