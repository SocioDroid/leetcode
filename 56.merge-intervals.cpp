/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 *
 * https://leetcode.com/problems/merge-intervals/description/
 *
 * algorithms
 * Medium (41.62%)
 * Likes:    7260
 * Dislikes: 383
 * Total Accepted:    888.2K
 * Total Submissions: 2.1M
 * Testcase Example:  '[[1,3],[2,6],[8,10],[15,18]]'
 *
 * Given an array of intervals where intervals[i] = [starti, endi], merge all
 * overlapping intervals, and return an array of the non-overlapping intervals
 * that cover all the intervals in the input.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
 * Output: [[1,6],[8,10],[15,18]]
 * Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into
 * [1,6].
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: intervals = [[1,4],[4,5]]
 * Output: [[1,5]]
 * Explanation: Intervals [1,4] and [4,5] are considered overlapping.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= intervals.length <= 10^4
 * intervals[i].length == 2
 * 0 <= starti <= endi <= 10^4
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& values) {
        
        
        sort( values.begin( ), values.end( ), [ ]( const auto& lhs, const auto& rhs )
        {
           return lhs[0] < rhs[0];
        });
        
        vector<vector<int>> ans;
        int curr = 0;
        
        for(int i=1; i < values.size(); i++)
        {
            
            if(values[curr][1] < values[i][0])
            {
                ans.push_back(values[curr]);
                curr = i;
            }
            else
            {
                values[curr][1] = max(values[curr][1], values[i][1])   ;            
            }
        }
        ans.push_back(values[curr]);
        return ans;
    }
};
// @lc code=end

