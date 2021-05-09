/*
 * @lc app=leetcode id=1550 lang=cpp
 *
 * [1550] Three Consecutive Odds
 *
 * https://leetcode.com/problems/three-consecutive-odds/description/
 *
 * algorithms
 * Easy (64.48%)
 * Likes:    215
 * Dislikes: 36
 * Total Accepted:    35.1K
 * Total Submissions: 54.4K
 * Testcase Example:  '[2,6,4,1]'
 *
 * Given an integer array arr, return true if there are three consecutive odd
 * numbers in the array. Otherwise, return false.
 * 
 * Example 1:
 * 
 * 
 * Input: arr = [2,6,4,1]
 * Output: false
 * Explanation: There are no three consecutive odds.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: arr = [1,2,34,3,4,5,7,23,12]
 * Output: true
 * Explanation: [5,7,23] are three consecutive odds.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= arr.length <= 1000
 * 1 <= arr[i] <= 1000
 * 
 * 
 */

// @lc code=start
class Solution:
    def threeConsecutiveOdds(self, arr: List[int]) -> bool:
        oddcount = 0
        for x in arr:
            if x%2 != 0:
                oddcount += 1
            else:
                oddcount = 0
            
            if oddcount == 3 :
                return True 
        return False
// @lc code=end

