/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 *
 * https://leetcode.com/problems/median-of-two-sorted-arrays/description/
 *
 * algorithms
 * Hard (31.63%)
 * Likes:    9959
 * Dislikes: 1529
 * Total Accepted:    935.6K
 * Total Submissions: 3M
 * Testcase Example:  '[1,3]\n[2]'
 *
 * Given two sorted arrays nums1 and nums2 of size m and n respectively, return
 * the median of the two sorted arrays.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums1 = [1,3], nums2 = [2]
 * Output: 2.00000
 * Explanation: merged array = [1,2,3] and median is 2.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums1 = [1,2], nums2 = [3,4]
 * Output: 2.50000
 * Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums1 = [0,0], nums2 = [0,0]
 * Output: 0.00000
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: nums1 = [], nums2 = [1]
 * Output: 1.00000
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: nums1 = [2], nums2 = []
 * Output: 2.00000
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * nums1.length == m
 * nums2.length == n
 * 0 <= m <= 1000
 * 0 <= n <= 1000
 * 1 <= m + n <= 2000
 * -10^6 <= nums1[i], nums2[i] <= 10^6
 * 
 * 
 * 
 * Follow up: The overall run time complexity should be O(log (m+n)).
 */

// @lc code=start
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
                
        int na = nums1.size();
        int nb = nums2.size();
        
        if (na > nb)
            return findMedianSortedArrays(nums2,nums1);
        
        int start = 0;
        int end = na;
        
        while(start <= end)
        {
            
            int partx = (start + end) /2;
            int party = (na+nb+1)/2 - partx;
            
            int maxleftx = (partx == 0) ? INT_MIN : nums1[partx-1];
            int maxrightx = (partx == na) ? INT_MAX : nums1[partx];
            int maxlefty = (party == 0) ? INT_MIN : nums2[party-1];
            int maxrighty = (party == nb) ? INT_MAX : nums2[party];
            
                if(maxleftx <= maxrighty && maxlefty <= maxrightx)
                    if((na+nb) %2 == 0)
                        return ((double)(max(maxleftx, maxlefty) + min(maxrightx, maxrighty))/ 2.0);
                    else
                        return(max(maxleftx, maxlefty));
                        
                else if(maxleftx > maxrighty)
                    end = partx - 1;    
                else 
                    start = partx + 1;
        }
        return 0;
    }
};
// @lc code=end

