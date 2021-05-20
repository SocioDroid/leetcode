/*
 * @lc app=leetcode id=52 lang=cpp
 *
 * [52] N-Queens II
 *
 * https://leetcode.com/problems/n-queens-ii/description/
 *
 * algorithms
 * Hard (60.89%)
 * Likes:    850
 * Dislikes: 185
 * Total Accepted:    163.4K
 * Total Submissions: 267.7K
 * Testcase Example:  '4'
 *
 * The n-queens puzzle is the problem of placing n queens on an n x n
 * chessboard such that no two queens attack each other.
 * 
 * Given an integer n, return the number of distinct solutions to the n-queens
 * puzzle.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 4
 * Output: 2
 * Explanation: There are two distinct solutions to the 4-queens puzzle as
 * shown.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 1
 * Output: 1
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 9
 * 
 * 
 */

// @lc code=start
class Solution {
public:

     bool check(vector<int> &qplace, int row, int col){        
        for(int i = 0; i<qplace.size(); i++){            
            if(col == qplace[i] || (row-i) == abs(col-qplace[i]))
                return false;            
        }
        return true;
    }

    bool solve(int n, vector<int>& qplace, int &ans){

        //         base
        if(n==qplace.size()){
            ans++;
            return false;     
        }

            //         search space
        for(int i = 0; i<qplace.size();i++){
            if(check(qplace,n,i)){
                qplace[n]=i;

                if(solve(n+1, qplace, ans))
                    return true;
            }            
        }

        qplace[n] = -1;
        return false;

    }

    int totalNQueens(int n) {
        vector<int>qplace(n,-1);
        int ans=0;

        solve(0,qplace, ans);

        return ans;
    }
};
// @lc code=end

