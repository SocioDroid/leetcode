/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 *
 * https://leetcode.com/problems/valid-palindrome/description/
 *
 * algorithms
 * Easy (38.73%)
 * Likes:    1971
 * Dislikes: 3828
 * Total Accepted:    856.5K
 * Total Submissions: 2.2M
 * Testcase Example:  '"A man, a plan, a canal: Panama"'
 *
 * Given a string s, determine if it is a palindrome, considering only
 * alphanumeric characters and ignoring cases.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "A man, a plan, a canal: Panama"
 * Output: true
 * Explanation: "amanaplanacanalpanama" is a palindrome.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "race a car"
 * Output: false
 * Explanation: "raceacar" is not a palindrome.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 2 * 10^5
 * s consists only of printable ASCII characters.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(string s) {
        
        // if (s.size() == 1)
    
        int l = 0, r = s.size();

        while(l < r)
        {
            while(!isalnum(s[l]) && l < r)
                l++;

            while(!isalnum(s[r]) && r > l)
                r--;

            if(tolower(s[l]) == tolower(s[r]))
            {
                l++;
                r--;
            }
            else
                return false;
        }
        return true;
    }
};
// @lc code=end

