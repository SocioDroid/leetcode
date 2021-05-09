/*
 * @lc app=leetcode id=994 lang=cpp
 *
 * [994] Rotting Oranges
 *
 * https://leetcode.com/problems/rotting-oranges/description/
 *
 * algorithms
 * Medium (49.75%)
 * Likes:    3334
 * Dislikes: 217
 * Total Accepted:    212.4K
 * Total Submissions: 426.9K
 * Testcase Example:  '[[2,1,1],[1,1,0],[0,1,1]]'
 *
 * You are given an m x n grid where each cell can have one of three
 * values:
 * 
 * 
 * 0 representing an empty cell,
 * 1 representing a fresh orange, or
 * 2 representing a rotten orange.
 * 
 * 
 * Every minute, any fresh orange that is 4-directionally adjacent to a rotten
 * orange becomes rotten.
 * 
 * Return the minimum number of minutes that must elapse until no cell has a
 * fresh orange. If this is impossible, return -1.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
 * Output: 4
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
 * Output: -1
 * Explanation: The orange in the bottom left corner (row 2, column 0) is never
 * rotten, because rotting only happens 4-directionally.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: grid = [[0,2]]
 * Output: 0
 * Explanation: Since there are already no fresh oranges at minute 0, the
 * answer is just 0.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == grid.length
 * n == grid[i].length
 * 1 <= m, n <= 10
 * grid[i][j] is 0, 1, or 2.
 * 
 * 
 */

// @lc code=start
class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        minute = 0
        
        rows = len(grid)
        columns = len(grid[0])
        
        def check_1(x, y):
            return True if grid[x][y] == 1 else False
        
        def rot(x,y, bool):    
            
            if x-1 >= 0:
                if check_1(x-1, y):
                    grid[x-1][y] = 2
                    bool = True
                                
            if x+1 < rows:
                if check_1(x+1, y):
                    grid[x+1][y] = 2
                    bool = True
                
            if y-1 >= 0:
                if check_1(x, y-1):
                    grid[x][y-1] = 2
                    bool = True
                    
            if y+1 < columns:
                if check_1(x, y+1):
                    grid[x][y+1] = 2
                    bool = True
            return bool
        
        for _ in range(100):
            coordinates = []
            one = []
            flag = False
            for x in range(rows):                
                for y in range(columns):
                    if grid[x][y] == 2:
                        grid[x][y] = 3
                        coordinates.append([x,y])                        
                    if grid[x][y] == 1:
                        one.append([x,y])

            if len(coordinates) == 0 and len(one) != 0:     
                return -1
            if len(coordinates) == 0:                
                break
            for i in range(len(coordinates)):
                flag = rot(coordinates[i][0], coordinates[i][1], flag)
            
            # print(flag)
            if flag:
                minute += 1
                
            # print(grid, minute)
        return minute
            
            
                
            
        
// @lc code=end

