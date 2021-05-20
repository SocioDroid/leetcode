/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 *
 * https://leetcode.com/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (66.02%)
 * Likes:    7874
 * Dislikes: 334
 * Total Accepted:    739.7K
 * Total Submissions: 1.1M
 * Testcase Example:  '3'
 *
 * Given n pairs of parentheses, write a function to generate all combinations
 * of well-formed parentheses.
 * 
 * 
 * Example 1:
 * Input: n = 3
 * Output: ["((()))","(()())","(())()","()(())","()()()"]
 * Example 2:
 * Input: n = 1
 * Output: ["()"]
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 8
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    // left ,right remaining parentheses
  
    
    void solve(int n, string ans, int left, int right, vector<string> &vans){
        if(ans.size()==n*2){        
            vans.push_back(ans);            
            return;
        }
        
        if( left<n ){
            ans+='(';
            solve(n, ans, left+1, right, vans);
            ans.erase(ans.end()-1);                        
        }
        
        if(right<left){
            ans+=')';
            solve(n, ans, left, right+1, vans);       
            ans.erase(ans.end()-1);            
        }
        
    }
    vector<string> generateParenthesis(int n) {
        
        string ans="";
        vector<string> vans;
        solve(n,ans,0,0, vans);
        return vans;
    }
};
// @lc code=end

