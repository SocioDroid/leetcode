/*
 * @lc app=leetcode id=90 lang=cpp
 *
 * [90] Subsets II
 *
 * https://leetcode.com/problems/subsets-ii/description/
 *
 * algorithms
 * Medium (49.37%)
 * Likes:    2491
 * Dislikes: 108
 * Total Accepted:    342.4K
 * Total Submissions: 693.5K
 * Testcase Example:  '[1,2,2]'
 *
 * Given an integer array nums that may contain duplicates, return all possible
 * subsets (the power set).
 * 
 * The solution set must not contain duplicate subsets. Return the solution in
 * any order.
 * 
 * 
 * Example 1:
 * Input: nums = [1,2,2]
 * Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
 * Example 2:
 * Input: nums = [0]
 * Output: [[],[0]]
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 10
 * -10 <= nums[i] <= 10
 * 
 * 
 */

// @lc code=start
class Solution {    
public:
    
    void printSet(set<vector<int>> temp){
        
        for(auto i : temp){
            for(auto j: i){
                cout<<j<<"\t";
            }
            cout<<endl;
        }
        
    }
    
    void printVect(vector<int> test){        
            for(auto j: test){
                cout<<j<<"\t";
            }
        cout<<endl;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> ans = {{}};
        // ans.insert({});
        
        for(auto i: nums){
            vector<vector<int>> temp;
            for(auto s: ans){
                s.push_back(i);
                // cout<<"printing s"<<endl;
                // printVect(s); 
                temp.push_back({s});
            }
            
            for(auto j: temp)
                ans.insert(j);                
            
            // cout<<"Printing ans for: "<<i<<endl;
            // printSet(ans);
            
            // ans.insert(ans.(), ans.end(), temp.begin(), temp.end(), ans.begin());            
        }        
        vector<vector<int>> op(ans.size());
        copy(ans.begin(),ans.end(),op.begin());
        
        return op;
        
    }
};
// @lc code=end

