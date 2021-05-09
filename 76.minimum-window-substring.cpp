/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 *
 * https://leetcode.com/problems/minimum-window-substring/description/
 *
 * algorithms
 * Hard (36.35%)
 * Likes:    6552
 * Dislikes: 442
 * Total Accepted:    531.8K
 * Total Submissions: 1.5M
 * Testcase Example:  '"ADOBECODEBANC"\n"ABC"'
 *
 * Given two strings s and t, return the minimum window in s which will contain
 * all the characters in t. If there is no such window in s that covers all
 * characters in t, return the empty string "".
 * 
 * Note that If there is such a window, it is guaranteed that there will always
 * be only one unique minimum window in s.
 * 
 * 
 * Example 1:
 * Input: s = "ADOBECODEBANC", t = "ABC"
 * Output: "BANC"
 * Example 2:
 * Input: s = "a", t = "a"
 * Output: "a"
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length, t.length <= 10^5
 * s and t consist of English letters.
 * 
 * 
 * 
 * Follow up: Could you find an algorithm that runs in O(n) time?
 */

// @lc code=start
class Solution {
public:
    
    
    string minWindow(string s, string t) 
    {   
        if(s.size() < t.size())
            return "";
        if(s==t)
            return s;
             
        
        int winstart = 0, winend = 0;
        
        unordered_map<char, int> umap;
        unordered_map<char, int> wincount;
        
        int subarr[] = {-1,0,0};
        
        for(int i = 0; i< t.size(); i++)
        {   
            int count = umap.find(t[i]) == umap.end() ? 0 : umap[t[i]];
            umap[t[i]] = count+1;
        }
                  
        int formed = 0, required = umap.size();
            
        for(winend = 0; winend<s.size(); winend++)
        {
            int c = s[winend];
            int count = wincount.find(c) == wincount.end() ? 0 : wincount[c];
            wincount[c] = count+1;
                       
            if(umap.find(c) != umap.end() && wincount[c] == umap[c])
                formed++;
            
            while(winstart <= winend && formed == required)
            {
                c = s[winstart];
                if(subarr[0] == -1 || winend-winstart+1 < subarr[0])
                {
                    subarr[0] = winend-winstart+1;
                    subarr[1] = winstart;
                    subarr[2] = winend;
                }
                
                wincount[c] -= 1;
                if(umap.find(c) != umap.end() && wincount[c] < umap[c])
                    formed--;
                winstart ++;
            }
        }
        
        return subarr[0] == -1 ? "": s.substr(subarr[1], subarr[0]);
            
    }
};
// @lc code=end

