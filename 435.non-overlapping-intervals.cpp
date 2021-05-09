/*
 * @lc app=leetcode id=435 lang=cpp
 *
 * [435] Non-overlapping Intervals
 *
 * https://leetcode.com/problems/non-overlapping-intervals/description/
 *
 * algorithms
 * Medium (44.12%)
 * Likes:    2055
 * Dislikes: 61
 * Total Accepted:    140.3K
 * Total Submissions: 317.9K
 * Testcase Example:  '[[1,2],[2,3],[3,4],[1,3]]'
 *
 * Given an array of intervals intervals where intervals[i] = [starti, endi],
 * return the minimum number of intervals you need to remove to make the rest
 * of the intervals non-overlapping.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
 * Output: 1
 * Explanation: [1,3] can be removed and the rest of the intervals are
 * non-overlapping.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: intervals = [[1,2],[1,2],[1,2]]
 * Output: 2
 * Explanation: You need to remove two [1,2] to make the rest of the intervals
 * non-overlapping.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: intervals = [[1,2],[2,3]]
 * Output: 0
 * Explanation: You don't need to remove any of the intervals since they're
 * already non-overlapping.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= intervals.length <= 2 * 10^4
 * intervals[i].length == 2
 * -2 * 10^4 <= starti < endi <= 2 * 10^4
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int last  = 0, count = 0;
        if(intervals.size()<2) return 0;   
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b){
           return a[0]<b[0]; 
        });
                
        for (int i=1; i<intervals.size(); i++)
        {
            if(intervals[i][0] < intervals[last][1]) //overlap
            {
                count++;
                if (intervals[i][1]<intervals[last][1]) last = i;
            }
            else{
                last = i;
            }
        }
        return count;
        
    }
};
// @lc code=end

