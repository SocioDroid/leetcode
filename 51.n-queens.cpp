/*
 * @lc app=leetcode id=51 lang=cpp
 *
 * [51] N-Queens
 *
 * https://leetcode.com/problems/n-queens/description/
 *
 * algorithms
 * Hard (50.60%)
 * Likes:    3005
 * Dislikes: 108
 * Total Accepted:    256.6K
 * Total Submissions: 505.2K
 * Testcase Example:  '4'
 *
 * The n-queens puzzle is the problem of placing n queens on an n x n
 * chessboard such that no two queens attack each other.
 * 
 * Given an integer n, return all distinct solutions to the n-queens puzzle.
 * 
 * Each solution contains a distinct board configuration of the n-queens'
 * placement, where 'Q' and '.' both indicate a queen and an empty space,
 * respectively.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 4
 * Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
 * Explanation: There exist two distinct solutions to the 4-queens puzzle as
 * shown above
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 1
 * Output: [["Q"]]
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
    
    bool solve(int n, vector<int>& qplace, vector<vector<string>>&ans){
        
        //         base
        if(n==qplace.size()){
            string  tans(n, '.');
            vector<string>tempv(n, tans);
            for(int x=0; x<qplace.size(); x++)
                tempv[x][qplace[x]] = 'Q';
            ans.push_back(tempv);
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
    vector<vector<string>> solveNQueens(int n) {
        string  tans(n, '.');
        vector<int>qplace(n,-1);
        vector<vector<string>>ans;        
        solve(0,qplace, ans);

        return ans;
    }
};
// @lc code=end

