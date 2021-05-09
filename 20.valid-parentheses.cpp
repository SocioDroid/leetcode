/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 *
 * https://leetcode.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (40.07%)
 * Likes:    7423
 * Dislikes: 303
 * Total Accepted:    1.4M
 * Total Submissions: 3.5M
 * Testcase Example:  '"()"'
 *
 * Given a string s containing just the characters '(', ')', '{', '}', '[' and
 * ']', determine if the input string is valid.
 * 
 * An input string is valid if:
 * 
 * 
 * Open brackets must be closed by the same type of brackets.
 * Open brackets must be closed in the correct order.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "()"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "()[]{}"
 * Output: true
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "(]"
 * Output: false
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: s = "([)]"
 * Output: false
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: s = "{[]}"
 * Output: true
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 10^4
 * s consists of parentheses only '()[]{}'.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        vector <char> v;
        if (s.length()==0)
            return false;
        if (s.length()%2)
            return false;
        for(int i=0; i< s.length(); i++)
        {
           if (s[i] == '(' || s[i]=='[' || s[i]=='{'){
               v.push_back(s[i]);              
           }            
        else if (v.size()){
                char c = v.back();            
                if( (c == '(' && s[i] == ')') || (c == '[' && s[i] == ']') || (c == '{' && s[i] == '}') ) 
                {
                    v.pop_back();                    
                }
                else return false;
            }            
            else
                return false;
        }
        if (v.size()==0)
            return true;
        return false;
    }
};
// @lc code=end

