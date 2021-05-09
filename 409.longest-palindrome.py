# /*
#  * @lc app=leetcode id=409 lang=cpp
#  *
#  * [409] Longest Palindrome
#  *
#  * https://leetcode.com/problems/longest-palindrome/description/
#  *
#  * algorithms
#  * Easy (52.31%)
#  * Likes:    1573
#  * Dislikes: 103
#  * Total Accepted:    201.2K
#  * Total Submissions: 384.5K
#  * Testcase Example:  '"abccccdd"'
#  *
#  * Given a string s which consists of lowercase or uppercase letters, return
#  * the length of the longest palindrome that can be built with those letters.
#  * 
#  * Letters are case sensitive, for example, "Aa" is not considered a palindrome
#  * here.
#  * 
#  * 
#  * Example 1:
#  * 
#  * 
#  * Input: s = "abccccdd"
#  * Output: 7
#  * Explanation:
#  * One longest palindrome that can be built is "dccaccd", whose length is 7.
#  * 
#  * 
#  * Example 2:
#  * 
#  * 
#  * Input: s = "a"
#  * Output: 1
#  * 
#  * 
#  * Example 3:
#  * 
#  * 
#  * Input: s = "bb"
#  * Output: 2
#  * 
#  * 
#  * 
#  * Constraints:
#  * 
#  * 
#  * 1 <= s.length <= 2000
#  * s consists of lowercase and/or uppercase English letters only.
#  * 
#  * 
#  */

# // @lc code=start
from collections import Counter
class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: int
        """
        count = Counter(s)
        ans = 0
        odd = 0
        for i in count:
            if count[i] % 2 == 1:
                odd += 1
            ans += count[i] // 2 * 2
            
        
        return ans+1 if odd else ans
                
            
            
        
#pythonsolution        


