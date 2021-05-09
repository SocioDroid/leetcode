/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 *
 * https://leetcode.com/problems/trapping-rain-water/description/
 *
 * algorithms
 * Hard (51.87%)
 * Likes:    11115
 * Dislikes: 166
 * Total Accepted:    738.8K
 * Total Submissions: 1.4M
 * Testcase Example:  '[0,1,0,2,1,0,1,3,2,1,2,1]'
 *
 * Given n non-negative integers representing an elevation map where the width
 * of each bar is 1, compute how much water it can trap after raining.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
 * Output: 6
 * Explanation: The above elevation map (black section) is represented by array
 * [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue
 * section) are being trapped.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: height = [4,2,0,3,2,5]
 * Output: 9
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * n == height.length
 * 0 <= n <= 3 * 10^4
 * 0 <= height[i] <= 10^5
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        
        if(height.size() < 3)        
            return 0;
        
        vector<int> lmax(height.size());
        vector<int> rmax( height.size());
        
        lmax[0] = height[0];
        rmax[height.size()-1] = height[height.size()-1];
        
        for(int i = 1, j = height.size()-2; i<height.size(); i++, j--)
        {
            lmax[i] = max(height[i], lmax[i-1]);
            rmax[j] = max(height[j], rmax[j+1]);          
        }
        
        
        for(int i = 0; i<height.size(); i++)
        {
            cout<<lmax[i]<<" "; 
        }
        cout<<endl;
        for(int i = 0; i<height.size(); i++)
        {
            cout<<rmax[i]<<" "; 
        }
        
        int sum =0;
        for(int i = 1; i < height.size(); i++)
        {
            sum += min(lmax[i], rmax[i]) - height[i];
        }
        return sum;
    }
};
// @lc code=end

