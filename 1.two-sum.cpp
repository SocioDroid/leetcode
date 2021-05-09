/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {        
        unordered_map <int,int> hmap;        
        
        for(int i=0; i< nums.size(); i++)
        {            
            if(hmap.find(target- nums[i]) != hmap.end())
            {
                return {hmap[target- nums[i]], i};                
            }
            hmap[nums[i]] = i;                            
        } 
        return {};
    }   
};
// @lc code=end

