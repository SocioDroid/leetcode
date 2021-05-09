/*
 * @lc app=leetcode id=1235 lang=cpp
 *
 * [1235] Maximum Profit in Job Scheduling
 *
 * https://leetcode.com/problems/maximum-profit-in-job-scheduling/description/
 *
 * algorithms
 * Hard (47.93%)
 * Likes:    1275
 * Dislikes: 14
 * Total Accepted:    40.4K
 * Total Submissions: 84.2K
 * Testcase Example:  '[1,2,3,3]\n[3,4,5,6]\n[50,10,40,70]'
 *
 * We have n jobs, where every job is scheduled to be done from startTime[i] to
 * endTime[i], obtaining a profit of profit[i].
 * 
 * You're given the startTime, endTime and profit arrays, return the maximum
 * profit you can take such that there are no two jobs in the subset with
 * overlapping time range.
 * 
 * If you choose a job that ends at time X you will be able to start another
 * job that starts at time X.
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input: startTime = [1,2,3,3], endTime = [3,4,5,6], profit = [50,10,40,70]
 * Output: 120
 * Explanation: The subset chosen is the first and fourth job. 
 * Time range [1-3]+[3-6] , we get profit of 120 = 50 + 70.
 * 
 * 
 * Example 2:
 * 
 * ⁠
 * 
 * 
 * Input: startTime = [1,2,3,4,6], endTime = [3,5,10,6,9], profit =
 * [20,20,100,70,60]
 * Output: 150
 * Explanation: The subset chosen is the first, fourth and fifth job. 
 * Profit obtained 150 = 20 + 70 + 60.
 * 
 * 
 * Example 3:
 * 
 * 
 * 
 * 
 * Input: startTime = [1,1,1], endTime = [2,3,4], profit = [5,6,4]
 * Output: 6
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= startTime.length == endTime.length == profit.length <= 5 * 10^4
 * 1 <= startTime[i] < endTime[i] <= 10^9
 * 1 <= profit[i] <= 10^4
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> sched;
        
        // insert all three elements (start,end,profit) into a single structure
        for(int i = 0; i < startTime.size(); ++i){
            sched.push_back({startTime[i],endTime[i],profit[i]});
        }
        
        // sort by end time 
        sort(begin(sched),end(sched),[](const vector<int> &v1, const vector<int> &v2){
           return v1[1] < v2[1]; 
        });
        
        vector<int> dp(sched.size(),0);
        dp[0] = sched[0][2];
        
        for(int i = 1; i < dp.size(); ++i){
            dp[i] = max(sched[i][2],dp[i - 1]);
            
            // perform a lower bound based on the start time of the current event
            // we want to find the first event that ends in a time <= than this start time
            auto before = lower_bound(begin(sched),begin(sched) + i,sched[i][0],
                                    [](const vector<int> &v1, const int val){
                                        return v1[1] <= val;
                                    });
            
            // lower bound can return an event that is > than what we're looking for.
            // Adjust accordingly
            while((*before)[1] > sched[i][0] && before != begin(sched)){
                before = prev(before);
            }
            
            // update the DP table
            if((*before)[1] <= sched[i][0]){
                dp[i] = max(dp[i],dp[distance(begin(sched),before)] + sched[i][2]);
            }
        }
        
        return dp[sched.size() - 1];
    }
};
// @lc code=end

