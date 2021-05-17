/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 *
 * https://leetcode.com/problems/longest-consecutive-sequence/description/
 *
 * algorithms
 * Hard (46.68%)
 * Likes:    5125
 * Dislikes: 254
 * Total Accepted:    404.3K
 * Total Submissions: 865.2K
 * Testcase Example:  '[100,4,200,1,3,2]'
 *
 * Given an unsorted array of integers nums, return the length of the longest
 * consecutive elements sequence.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [100,4,200,1,3,2]
 * Output: 4
 * Explanation: The longest consecutive elements sequence is [1, 2, 3, 4].
 * Therefore its length is 4.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [0,3,7,2,5,8,4,6,0,1]
 * Output: 9
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= nums.length <= 10^4
 * -10^9 <= nums[i] <= 10^9
 * 
 * 
 * 
 * Follow up: Could you implement the O(n) solution?
 */

// @lc code=start
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        // set<int> s(nums.begin(), nums.end());
        int maxcount = 0;
        
        unordered_map<int,bool> s;
        
        for(auto i: nums){
            s[i] = true;
        }
        
        for(int num : nums){
            
            if(s.find(num-1) == s.end()){
                
                int currnum = num;
                int currstreak = 1;
                while(s.find(currnum+1) != s.end()){    
                    currnum += 1;
                    currstreak+=1;
                }
                
                maxcount = max(maxcount, currstreak);
            }
        }
        
        return maxcount;
    }
};
// @lc code=end

