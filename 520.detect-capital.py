# /*
#  * @lc app=leetcode id=520 lang=cpp
#  *
#  * [520] Detect Capital
#  *
#  * https://leetcode.com/problems/detect-capital/description/
#  *
#  * algorithms
#  * Easy (54.17%)
#  * Likes:    821
#  * Dislikes: 293
#  * Total Accepted:    192.5K
#  * Total Submissions: 355.4K
#  * Testcase Example:  '"USA"'
#  *
#  * We define the usage of capitals in a word to be right when one of the
#  * following cases holds:
#  * 
#  * 
#  * All letters in this word are capitals, like "USA".
#  * All letters in this word are not capitals, like "leetcode".
#  * Only the first letter in this word is capital, like "Google".
#  * 
#  * 
#  * Given a string word, return true if the usage of capitals in it is right.
#  * 
#  * 
#  * Example 1:
#  * Input: word = "USA"
#  * Output: true
#  * Example 2:
#  * Input: word = "FlaG"
#  * Output: false
#  * 
#  * 
#  * Constraints:
#  * 
#  * 
#  * 1 <= word.length <= 100
#  * word consists of lowercase and uppercase English letters.
#  * 
#  * 
#  */

# // @lc code=start
class Solution:
    def detectCapitalUse(self, word: str) -> bool:
        if word.isupper():
            return True
        elif word.islower():
            return True
        elif word[0].isupper() and word[1:].islower():        
            return True
        return False                                    
#pythonsolution        
# // @lc code=end

