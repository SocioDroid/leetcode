/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 *
 * https://leetcode.com/problems/container-with-most-water/description/
 *
 * algorithms
 * Medium (52.96%)
 * Likes:    9391
 * Dislikes: 709
 * Total Accepted:    939.8K
 * Total Submissions: 1.8M
 * Testcase Example:  '[1,8,6,2,5,4,8,3,7]'
 *
 * Given n non-negative integers a1, a2, ..., an , where each represents a
 * point at coordinate (i, ai). n vertical lines are drawn such that the two
 * endpoints of the line i is at (i, ai) and (i, 0). Find two lines, which,
 * together with the x-axis forms a container, such that the container contains
 * the most water.
 * 
 * Notice that you may not slant the container.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: height = [1,8,6,2,5,4,8,3,7]
 * Output: 49
 * Explanation: The above vertical lines are represented by array
 * [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the
 * container can contain is 49.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: height = [1,1]
 * Output: 1
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: height = [4,3,2,1,4]
 * Output: 16
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: height = [1,2,1]
 * Output: 2
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * n == height.length
 * 2 <= n <= 10^5
 * 0 <= height[i] <= 10^4
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int size = height.size();
        int max_area=0;
        
        int i=0;
        int j=size-1;
        
        while(i<j)
        {
            max_area = max(max_area, min(height[i],height[j]) * (j-i) ) ;
            
            if(height[i]<height[j])
            {
                i++;
            }
            else if(height[i]>height[j])
            {
                j--;
            }
            else
            {
                j--;
                i++;
            }
            
        }
        
        return max_area;
    }
};
// @lc code=end

