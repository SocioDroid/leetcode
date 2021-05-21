/*
 * @lc app=leetcode id=63 lang=cpp
 *
 * [63] Unique Paths II
 *
 * https://leetcode.com/problems/unique-paths-ii/description/
 *
 * algorithms
 * Medium (35.88%)
 * Likes:    2925
 * Dislikes: 300
 * Total Accepted:    386.8K
 * Total Submissions: 1.1M
 * Testcase Example:  '[[0,0,0],[0,1,0],[0,0,0]]'
 *
 * A robot is located at the top-left corner of a m x n grid (marked 'Start' in
 * the diagram below).
 * 
 * The robot can only move either down or right at any point in time. The robot
 * is trying to reach the bottom-right corner of the grid (marked 'Finish' in
 * the diagram below).
 * 
 * Now consider if some obstacles are added to the grids. How many unique paths
 * would there be?
 * 
 * An obstacle and space is marked as 1 and 0 respectively in the grid.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
 * Output: 2
 * Explanation: There is one obstacle in the middle of the 3x3 grid above.
 * There are two ways to reach the bottom-right corner:
 * 1. Right -> Right -> Down -> Down
 * 2. Down -> Down -> Right -> Right
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: obstacleGrid = [[0,1],[0,0]]
 * Output: 1
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == obstacleGrid.length
 * n == obstacleGrid[i].length
 * 1 <= m, n <= 100
 * obstacleGrid[i][j] is 0 or 1.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int dp[101][101];
    void solve(vector<vector<int>>& grid){
        int m = grid.size(), n = grid[0].size();
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j])
                    continue;
                if(i==0 && j == 0)
                    dp[i][j ]=1;
                else if(i==0 )
                    dp[i][j] += dp[i][j-1];
                else if(j==0 )
                    dp[i][j] += dp[i-1][j];
                else
                    dp[i][j] += dp[i-1][j]+dp[i][j-1];                
            }
        }
        
    }  
    
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        memset(dp, 0, sizeof(dp));
        solve(grid);    
        return dp[grid.size()-1][grid[0].size()-1];
    }
};
// @lc code=end

