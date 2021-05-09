/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 *
 * https://leetcode.com/problems/group-anagrams/description/
 *
 * algorithms
 * Medium (60.01%)
 * Likes:    5380
 * Dislikes: 232
 * Total Accepted:    915.7K
 * Total Submissions: 1.5M
 * Testcase Example:  '["eat","tea","tan","ate","nat","bat"]'
 *
 * Given an array of strings strs, group the anagrams together. You can return
 * the answer in any order.
 * 
 * An Anagram is a word or phrase formed by rearranging the letters of a
 * different word or phrase, typically using all the original letters exactly
 * once.
 * 
 * 
 * Example 1:
 * Input: strs = ["eat","tea","tan","ate","nat","bat"]
 * Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
 * Example 2:
 * Input: strs = [""]
 * Output: [[""]]
 * Example 3:
 * Input: strs = ["a"]
 * Output: [["a"]]
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= strs.length <= 10^4
 * 0 <= strs[i].length <= 100
 * strs[i] consists of lower-case English letters.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
           
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if(strs.size()==1)        
            return {{strs[0]}};
        
        unordered_map<string, vector<string>> umap;
        
        for(int i =0; i<strs.size(); i++)
        {
            string temp = strs[i];
            sort(temp.begin(),temp.end());
            umap[temp].push_back(strs[i]);
        }     
        
        vector<vector<string>> ans;
        
        for(auto i: umap)
        {
            vector<string> temp;
            
            for(int j =0; j<i.second.size(); j++)
            {
                temp.push_back(i.second[j]);
            }
                        
            ans.push_back(temp);
        }
        return ans;
                
    }
};
// @lc code=end

