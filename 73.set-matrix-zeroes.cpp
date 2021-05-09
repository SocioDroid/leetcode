/*
 * @lc app=leetcode id=73 lang=cpp
 *
 * [73] Set Matrix Zeroes
 *
 * https://leetcode.com/problems/set-matrix-zeroes/description/
 *
 * algorithms
 * Medium (44.76%)
 * Likes:    3413
 * Dislikes: 367
 * Total Accepted:    426.3K
 * Total Submissions: 952.3K
 * Testcase Example:  '[[1,1,1],[1,0,1],[1,1,1]]'
 *
 * Given an m x n matrix. If an element is 0, set its entire row and column to
 * 0. Do it in-place.
 * 
 * Follow up:
 * 
 * 
 * A straight forward solution using O(mn) space is probably a bad idea.
 * A simple improvement uses O(m + n) space, but still not the best
 * solution.
 * Could you devise a constant space solution?
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
 * Output: [[1,0,1],[0,0,0],[1,0,1]]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
 * Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == matrix.length
 * n == matrix[0].length
 * 1 <= m, n <= 200
 * -2^31 <= matrix[i][j] <= 2^31 - 1
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        
        int m = mat.size();
        int n = mat[0].size();
                
        set <int> row;
        set <int> col;
    
        set<int>::iterator iter;
            
        for(int i=0 ; i<m; i++)
        {
            for(int j=0 ; j<n; j++)
            {
                if(mat[i][j] == 0) 
                {
                    row.insert(i);
                    col.insert(j);
                }
            }
            
        }
        
        for(iter = row.begin(); iter != row.end(); iter++)
        {
            for(int i=0; i < n; i++)
                mat[*iter][i] = 0;
        }

        for(iter = col.begin(); iter != col.end(); iter++)
        {
            for(int i=0; i < m; i++)
                mat[i][*iter] = 0;
        }
        
    }
};
// @lc code=end

