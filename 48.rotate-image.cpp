/*
 * @lc app=leetcode id=48 lang=cpp
 *
 * [48] Rotate Image
 *
 * https://leetcode.com/problems/rotate-image/description/
 *
 * algorithms
 * Medium (61.32%)
 * Likes:    4971
 * Dislikes: 343
 * Total Accepted:    584.3K
 * Total Submissions: 952.7K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * You are given an n x n 2D matrix representing an image, rotate the image by
 * 90 degrees (clockwise).
 * 
 * You have to rotate the image in-place, which means you have to modify the
 * input 2D matrix directly. DO NOT allocate another 2D matrix and do the
 * rotation.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
 * Output: [[7,4,1],[8,5,2],[9,6,3]]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
 * Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: matrix = [[1]]
 * Output: [[1]]
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: matrix = [[1,2],[3,4]]
 * Output: [[3,1],[4,2]]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * matrix.length == n
 * matrix[i].length == n
 * 1 <= n <= 20
 * -1000 <= matrix[i][j] <= 1000
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<vector<int>>& mat) {
        
        int n = mat.size();
        
        for(int j=0; j<n; j++)
        {
            for(int i=0; i<n/2; i++)
            {
                int temp = mat[i][j];
                mat[i][j] = mat[n-1-i][j];
                mat[n-1-i][j] = temp;
            }            
        }
        
        // for(int i=0; i<n; i++)
        // {
        //     for(int j=0; j<n; j++)                
        //     {
        //         cout<< mat[i][j] << "\t"; 
        //     }
        //     cout << "\n";
        // }
        
        
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)                
            {
                int temp = mat[i][j];
                mat[i][j] = mat[j][i];
                mat[j][i] = temp;
            }
        }
        
    }
};
// @lc code=end

