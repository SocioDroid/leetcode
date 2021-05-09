/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 *
 * https://leetcode.com/problems/search-in-rotated-sorted-array/description/
 *
 * algorithms
 * Medium (36.26%)
 * Likes:    7629
 * Dislikes: 669
 * Total Accepted:    986.9K
 * Total Submissions: 2.7M
 * Testcase Example:  '[4,5,6,7,0,1,2]\n0'
 *
 * There is an integer array nums sorted in ascending order (with distinct
 * values).
 * 
 * Prior to being passed to your function, nums is rotated at an unknown pivot
 * index k (0 <= k < nums.length) such that the resulting array is [nums[k],
 * nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed).
 * For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become
 * [4,5,6,7,0,1,2].
 * 
 * Given the array nums after the rotation and an integer target, return the
 * index of target if it is in nums, or -1 if it is not in nums.
 * 
 * You must write an algorithm with O(log n) runtime complexity.
 * 
 * 
 * Example 1:
 * Input: nums = [4,5,6,7,0,1,2], target = 0
 * Output: 4
 * Example 2:
 * Input: nums = [4,5,6,7,0,1,2], target = 3
 * Output: -1
 * Example 3:
 * Input: nums = [1], target = 0
 * Output: -1
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 5000
 * -10^4 <= nums[i] <= 10^4
 * All values of nums are unique.
 * nums is guaranteed to be rotated at some pivot.
 * -10^4 <= target <= 10^4
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        
        int start = 0, end = nums.size()-1;
        
        
        while(start <= end)
        {
            int mid = (start+end)/2;
            
            if(nums[mid] == target)
                return mid;
            
            if(nums[start] <= nums[mid])
            {
                if(nums[start] <= target && target <= nums[mid])
                    end = mid-1;
                else
                    start = mid+1;
            }
            else                
            {
                if(nums[mid] <= target && target <= nums[end])
                    start = mid+1;
                else
                    end = mid-1;                
            }
        }
        return -1;
    }
};
// @lc code=end

