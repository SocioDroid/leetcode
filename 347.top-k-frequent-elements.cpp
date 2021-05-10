/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 *
 * https://leetcode.com/problems/top-k-frequent-elements/description/
 *
 * algorithms
 * Medium (62.72%)
 * Likes:    4940
 * Dislikes: 269
 * Total Accepted:    587.4K
 * Total Submissions: 936.4K
 * Testcase Example:  '[1,1,1,2,2,3]\n2'
 *
 * Given an integer array nums and an integer k, return the k most frequent
 * elements. You may return the answer in any order.
 * 
 * 
 * Example 1:
 * Input: nums = [1,1,1,2,2,3], k = 2
 * Output: [1,2]
 * Example 2:
 * Input: nums = [1], k = 1
 * Output: [1]
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 10^5
 * k is in the range [1, the number of unique elements in the array].
 * It is guaranteed that the answer is unique.
 * 
 * 
 * 
 * Follow up: Your algorithm's time complexity must be better than O(n log n),
 * where n is the array's size.
 * 
 */

// @lc code=start
class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        map<int, int> freq;

        struct cmp
        {
            bool operator()(const pair<int,int> &a, const pair<int,int> &b)
            {
                return a.second > b.second;
            };
        };

        for (int i : nums)
        {
            freq[i]++;
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;

        for(auto it = freq.begin(); it!=freq.end(); ++it){
            pair<int,int> p;

            p.first = it->first;
            p.second = it->second;

            pq.push(p);
            // cout<<"Pushing : "<<p.first<<"\t"<<p.second<<endl;
            
            if(pq.size() == k+1){
                // cout<<"Poppping : "<<pq.top().first<<"\t"<<pq.top().second<<endl;
                pq.pop();            
            }
        }

        vector<int> ans;

        while(!pq.empty()){
            ans.push_back(pq.top().first);
            pq.pop();
        }
        return ans;
    }
};
// @lc code=end
