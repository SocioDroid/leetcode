# /*
#  * @lc app=leetcode id=342 lang=cpp
#  *
#  * [342] Power of Four
#  *
#  * https://leetcode.com/problems/power-of-four/description/
#  *
#  * algorithms
#  * Easy (41.94%)
#  * Likes:    876
#  * Dislikes: 253
#  * Total Accepted:    229.6K
#  * Total Submissions: 547.5K
#  * Testcase Example:  '16'
#  *
#  * Given an integer n, return true if it is a power of four. Otherwise, return
#  * false.
#  * 
#  * An integer n is a power of four, if there exists an integer x such that n ==
#  * 4^x.
#  * 
#  * 
#  * Example 1:
#  * Input: n = 16
#  * Output: true
#  * Example 2:
#  * Input: n = 5
#  * Output: false
#  * Example 3:
#  * Input: n = 1
#  * Output: true
#  * 
#  * 
#  * Constraints:
#  * 
#  * 
#  * -2^31 <= n <= 2^31 - 1
#  * 
#  * 
#  * 
#  * Follow up: Could you solve it without loops/recursion?
#  */

# // @lc code=start
class Solution:
    def isPowerOfFour(self, num: int) -> bool:
        if num <= 0:
            return False
        return math.pow(4,int(math.log(num,4))) == num
                

#pythonsolution        

