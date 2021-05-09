/*
 * @lc app=leetcode id=1047 lang=cpp
 *
 * [1047] Remove All Adjacent Duplicates In String
 *
 * https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/description/
 *
 * algorithms
 * Easy (71.54%)
 * Likes:    1584
 * Dislikes: 98
 * Total Accepted:    146K
 * Total Submissions: 204K
 * Testcase Example:  '"abbaca"'
 *
 * Given a string S of lowercase letters, a duplicate removal consists of
 * choosing two adjacent and equal letters, and removing them.
 * 
 * We repeatedly make duplicate removals on S until we no longer can.
 * 
 * Return the final string after all such duplicate removals have been made.
 * It is guaranteed the answer is unique.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: "abbaca"
 * Output: "ca"
 * Explanation: 
 * For example, in "abbaca" we could remove "bb" since the letters are adjacent
 * and equal, and this is the only possible move.  The result of this move is
 * that the string is "aaca", of which only "aa" is possible, so the final
 * string is "ca".
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= S.length <= 20000
 * S consists only of English lowercase letters.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string removeDuplicates(string word) {
        stack<char> s;        
        
        for(int i = 0; i<word.length();i++)
        {
            if( s.size()>0 && word[i] == s.top())
            {
                cout<<"pop\t"<<s.top()<<"\n";
                s.pop();
            }
            else
            {
                cout<<"pushing\t"<<word[i]<<"\n";
                s.push(word[i]);
            }
        }
        
        string ans;
        while(!s.empty())
        {
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end

