/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 *
 * https://leetcode.com/problems/spiral-matrix/description/
 *
 * algorithms
 * Medium (36.79%)
 * Likes:    3815
 * Dislikes: 669
 * Total Accepted:    496.3K
 * Total Submissions: 1.3M
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * Given an m x n matrix, return all elements of the matrix in spiral order.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
 * Output: [1,2,3,6,9,8,7,4,5]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
 * Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == matrix.length
 * n == matrix[i].length
 * 1 <= m, n <= 10
 * -100 <= matrix[i][j] <= 100
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        
        int m = mat.size();
        int n = mat[0].size();
        int max = m*n;    
        vector <int> ans;
        
        int top = 0, down = m-1;
        int left = 0, right = n-1;
        
        int dir = 0;
        
        while(ans.size() < max)
        {
            if(dir == 0)
            {
                for(int i = left; i<=right; i++)
                    ans.push_back(mat[top][i]);
                top++;
            }
            else if(dir == 1)
            {
                for(int i = top; i<=down; i++)
                    ans.push_back(mat[i][right]);
                right--;
            }
            else if(dir == 2)
            {
                for(int i = right; i>=left; i--)                
                    ans.push_back(mat[down][i]);                
                down--;
            }
            else if( dir == 3 )
            {
                for(int i = down; i>=top; i--)                                
                    ans.push_back(mat[i][left]);                
                left ++;
            }
            dir = (dir+1)%4;
        }
        return ans;
    }
};
// @lc code=end

