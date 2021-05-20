/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 *
 * https://leetcode.com/problems/next-permutation/description/
 *
 * algorithms
 * Medium (33.99%)
 * Likes:    5616
 * Dislikes: 1910
 * Total Accepted:    517.4K
 * Total Submissions: 1.5M
 * Testcase Example:  '[1,2,3]'
 *
 * Implement next permutation, which rearranges numbers into the
 * lexicographically next greater permutation of numbers.
 * 
 * If such an arrangement is not possible, it must rearrange it as the lowest
 * possible order (i.e., sorted in ascending order).
 * 
 * The replacement must be in place and use only constant extra memory.
 * 
 * 
 * Example 1:
 * Input: nums = [1,2,3]
 * Output: [1,3,2]
 * Example 2:
 * Input: nums = [3,2,1]
 * Output: [1,2,3]
 * Example 3:
 * Input: nums = [1,1,5]
 * Output: [1,5,1]
 * Example 4:
 * Input: nums = [1]
 * Output: [1]
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 100
 * 0 <= nums[i] <= 100
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return; 
        
        vector<int> tnums = nums;
        
        int i = n-1;
        
        while(i>0 && tnums[i]<=tnums[i-1]){
            i--;                
        }
        
        i = i-1;
        if(i == -1){
            reverse(nums.begin(), nums.end());
            return;
        }
        
        int mindif = INT_MAX;
        int ti = i+1;
        int tempidx = -1;
        
        while(ti<n && tnums[i]<tnums[ti] && tnums[ti]-tnums[i]<=mindif){                                   
            tempidx = ti;
            mindif = tnums[ti]-tnums[i];
            ti+=1;                        
        }
        // swap
        swap(tnums[tempidx], tnums[i]);
  
        reverse(tnums.begin()+i+1, tnums.end());
        nums = tnums;
    }
};
// @lc code=end

