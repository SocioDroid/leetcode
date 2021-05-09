/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 *
 * https://leetcode.com/problems/3sum/description/
 *
 * algorithms
 * Medium (28.43%)
 * Likes:    10420
 * Dislikes: 1066
 * Total Accepted:    1.3M
 * Total Submissions: 4.5M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * Given an integer array nums, return all the triplets [nums[i], nums[j],
 * nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] +
 * nums[k] == 0.
 * 
 * Notice that the solution set must not contain duplicate triplets.
 * 
 * 
 * Example 1:
 * Input: nums = [-1,0,1,2,-1,-4]
 * Output: [[-1,-1,2],[-1,0,1]]
 * Example 2:
 * Input: nums = []
 * Output: []
 * Example 3:
 * Input: nums = [0]
 * Output: []
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= nums.length <= 3000
 * -10^5 <= nums[i] <= 10^5
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int size = nums.size();
        
        vector<vector<int>> answer;
        
        if (size<3) return answer;   
        
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < size; i++)
        {
            
            int target = -nums[i];
            if(target<0)
                break;
            if(i && nums[i]==nums[i-1]) continue;
            
            int y = i+1;
            int z = size - 1;
            
            vector<vector <int>> temp;
            while(y<z)
            {
                int sum = nums[i]+nums[y]+nums[z];
                if(sum < 0)
                {
                    y++;
                }
                else if(sum > 0)
                {
                    z--;
                }
                else
                {                    
                    answer.push_back({nums[i], nums[y], nums[z]});
                    y++;
                    while(nums[y] == nums[y-1] && y < z)
                        y++;
                }
            }
        } 
        return answer;
    }
};
// @lc code=end

