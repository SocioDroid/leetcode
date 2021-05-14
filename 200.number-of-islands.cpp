/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 *
 * https://leetcode.com/problems/number-of-islands/description/
 *
 * algorithms
 * Medium (49.87%)
 * Likes:    8434
 * Dislikes: 243
 * Total Accepted:    1M
 * Total Submissions: 2.1M
 * Testcase Example:  '[["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]'
 *
 * Given an m x n 2D binary grid grid which represents a map of '1's (land) and
 * '0's (water), return the number of islands.
 * 
 * An island is surrounded by water and is formed by connecting adjacent lands
 * horizontally or vertically. You may assume all four edges of the grid are
 * all surrounded by water.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: grid = [
 * ⁠ ["1","1","1","1","0"],
 * ⁠ ["1","1","0","1","0"],
 * ⁠ ["1","1","0","0","0"],
 * ⁠ ["0","0","0","0","0"]
 * ]
 * Output: 1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: grid = [
 * ⁠ ["1","1","0","0","0"],
 * ⁠ ["1","1","0","0","0"],
 * ⁠ ["0","0","1","0","0"],
 * ⁠ ["0","0","0","1","1"]
 * ]
 * Output: 3
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == grid.length
 * n == grid[i].length
 * 1 <= m, n <= 300
 * grid[i][j] is '0' or '1'.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    
    vector<vector<int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};

    void dfs(vector<vector<char>> &grid, int i, int j){
        

        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() )
            return;
        
        if(grid[i][j] == 'X' || grid[i][j] == '0')
            return;
        
        grid[i][j] = 'X';
        
        for(auto d: dir){
                dfs(grid, i+d[0], j+d[1]);        
        }
        
    }
    
    int numIslands(vector<vector<char>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        
        
        int islands= 0;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j] == '1' ){
                    dfs(grid, i , j);
                    islands++;  
                }
                
            }
        }
        
        return islands;
        
    }
};
// @lc code=end

