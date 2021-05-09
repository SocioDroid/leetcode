/*
 * @lc app=leetcode id=238 lang=cpp
 *
 * [238] Product of Array Except Self
 *
 * https://leetcode.com/problems/product-of-array-except-self/description/
 *
 * algorithms
 * Medium (61.35%)
 * Likes:    7349
 * Dislikes: 553
 * Total Accepted:    767.3K
 * Total Submissions: 1.3M
 * Testcase Example:  '[1,2,3,4]'
 *
 * Given an integer array nums, return an array answer such that answer[i] is
 * equal to the product of all the elements of nums except nums[i].
 * 
 * The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit
 * integer.
 * 
 * 
 * Example 1:
 * Input: nums = [1,2,3,4]
 * Output: [24,12,8,6]
 * Example 2:
 * Input: nums = [-1,1,0,-3,3]
 * Output: [0,0,9,0,0]
 * 
 * 
 * Constraints:
 * 
 * 
 * 2 <= nums.length <= 10^5
 * -30 <= nums[i] <= 30
 * The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit
 * integer.
 * 
 * 
 * 
 * Follow up:
 * 
 * 
 * Could you solve it in O(n) time complexity and without using division?
 * Could you solve it with O(1) constant space complexity? (The output array
 * does not count as extra space for space complexity analysis.)
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& v) {
        vector<int> ans;
        
        int flag=0;
        int mul = 1;
        for(int i=0; i< v.size(); i++)
        {
            if(!v[i])
                flag++;
            else    
                mul *= v[i];
        }
        
        if(flag>1)
        {
            vector<int> vect(v.size(), 0);
            return vect;
        }
        else if(flag)
        {
                for(int i=0; i< v.size(); i++)
                {
                    if(!v[i])
                        ans.push_back( mul );
                    else
                        ans.push_back(0);
                }
        }
        else
        {
             for(int i=0; i< v.size(); i++)
            {
                 ans.push_back( mul/v[i] );
            }
        }
        return ans;
    }
};
// @lc code=end

