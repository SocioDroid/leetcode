/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 *
 * https://leetcode.com/problems/maximum-subarray/description/
 *
 * algorithms
 * Easy (47.97%)
 * Likes:    11818
 * Dislikes: 570
 * Total Accepted:    1.4M
 * Total Submissions: 2.9M
 * Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]'
 *
 * Given an integer array nums, find the contiguous subarray (containing at
 * least one number) which has the largest sum and return its sum.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
 * Output: 6
 * Explanation: [4,-1,2,1] has the largest sum = 6.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1]
 * Output: 1
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [5,4,-1,7,8]
 * Output: 23
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 3 * 10^4
 * -10^5 <= nums[i] <= 10^5
 * 
 * 
 * 
 * Follow up: If you have figured out the O(n) solution, try coding another
 * solution using the divide and conquer approach, which is more subtle.
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        // if(nums.size()==1)
        //     return nums[0];
        
        int max_num = *max_element(nums.begin(), nums.end());
        if(max_num < 0)
            return max_num;
        int max=0;
        int curr=0;
        
        for (int i : nums)
        {
          if(curr+i > -1)
          {
              curr = curr+i   ;
              if (curr>max) max = curr;                  
          }
            else curr=0;
        }
        return max;
    }
};
// @lc code=end

