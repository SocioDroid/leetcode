/*
 * @lc app=leetcode id=680 lang=cpp
 *
 * [680] Valid Palindrome II
 *
 * https://leetcode.com/problems/valid-palindrome-ii/description/
 *
 * algorithms
 * Easy (37.20%)
 * Likes:    2591
 * Dislikes: 167
 * Total Accepted:    264.3K
 * Total Submissions: 710.3K
 * Testcase Example:  '"aba"'
 *
 * Given a string s, return true if the s can be palindrome after deleting at
 * most one character from it.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "aba"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "abca"
 * Output: true
 * Explanation: You could delete the character 'c'.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "abc"
 * Output: false
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 10^5
 * s consists of lowercase English letters.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool validPalindrome(string s) {
        
        int n = s.size(), h =  (n)/ 2;
        
        for(int i = 0; i<h; i++)
        {
            if(s[i] != s[n-i-1])
            {
                for(int j =i; j < h; j++)            
                    if(s[j] != s[n-1-j-1] && s[j+1] != s[n-1-j])
                        return false;
                    return true;                
            }
            
        }        
        return true;
    }
};
// @lc code=end

