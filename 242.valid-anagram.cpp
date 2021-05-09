/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 *
 * https://leetcode.com/problems/valid-anagram/description/
 *
 * algorithms
 * Easy (59.05%)
 * Likes:    2605
 * Dislikes: 164
 * Total Accepted:    816.6K
 * Total Submissions: 1.4M
 * Testcase Example:  '"anagram"\n"nagaram"'
 *
 * Given two strings s and t, return true if t is an anagram of s, and false
 * otherwise.
 * 
 * 
 * Example 1:
 * Input: s = "anagram", t = "nagaram"
 * Output: true
 * Example 2:
 * Input: s = "rat", t = "car"
 * Output: false
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length, t.length <= 5 * 10^4
 * s and t consist of lowercase English letters.
 * 
 * 
 * 
 * Follow up: What if the inputs contain Unicode characters? How would you
 * adapt your solution to such a case?
 * 
 */

// @lc code=start
class Solution {
public:
    bool isAnagram(string s, string t) {
        
        if(s.length()!= t.length())
            return false;
            
        unordered_map <char,int> smap;
        
        for(int i=0;i<s.length();i++)
        {
                smap[s[i]]++;
                smap[t[i]]--;        
        }
        
        for(int i=0;i<s.length();i++)
        {
            if(smap[s[i]]!=0)    
                return false;
                        
        }
        return true;
        
    }      
};
// @lc code=end

