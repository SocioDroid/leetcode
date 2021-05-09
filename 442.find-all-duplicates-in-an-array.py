# /*
#  * @lc app=leetcode id=442 lang=cpp
#  *
#  * [442] Find All Duplicates in an Array
#  *
#  * https://leetcode.com/problems/find-all-duplicates-in-an-array/description/
#  *
#  * algorithms
#  * Medium (69.35%)
#  * Likes:    3573
#  * Dislikes: 184
#  * Total Accepted:    271.8K
#  * Total Submissions: 392K
#  * Testcase Example:  '[4,3,2,7,8,2,3,1]'
#  *
#  * Given an integer array nums of length n where all the integers of nums are
#  * in the range [1, n] and each integer appears once or twice, return an array
#  * of all the integers that appears twice.
#  * 
#  * 
#  * Example 1:
#  * Input: nums = [4,3,2,7,8,2,3,1]
#  * Output: [2,3]
#  * Example 2:
#  * Input: nums = [1,1,2]
#  * Output: [1]
#  * Example 3:
#  * Input: nums = [1]
#  * Output: []
#  * 
#  * 
#  class Solution:
#     def findDuplicates(self, nums: List[int]) -> List[int]:
#         l = []
#         for n in nums:
#             n = abs(n)
#             if nums[n-1] > 0: nums[n-1] *= -1                
#             else:
#                 l.append(n)
#         return l
                
#         * Constraints:
#  * 
#  * 
#  * n == nums.length
#  * 1 <= n <= 10^5
#  * 1 <= nums[i] <= n
#  * Each element in nums appears once or twice.
#  * 
#  * 
#  * 
#  * Follow up: Could you do it without extra space and in O(n) runtime?
#  * 
#  */

# // @lc code=start
class Solution:
    def findDuplicates(self, nums: List[int]) -> List[int]:
        l = []
        for n in nums:
            n = abs(n)
            if nums[n-1] > 0: nums[n-1] *= -1                
            else:
                l.append(n)
        return l
                
        
#pythonsolution        
# // @lc code=end

