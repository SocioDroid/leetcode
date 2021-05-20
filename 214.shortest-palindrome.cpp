/*
 * @lc app=leetcode id=214 lang=cpp
 *
 * [214] Shortest Palindrome
 *
 * https://leetcode.com/problems/shortest-palindrome/description/
 *
 * algorithms
 * Hard (30.86%)
 * Likes:    1650
 * Dislikes: 155
 * Total Accepted:    116.2K
 * Total Submissions: 376K
 * Testcase Example:  '"aacecaaa"'
 *
 * You are given a string s. You can convert s to a palindrome by adding
 * characters in front of it.
 * 
 * Return the shortest palindrome you can find by performing this
 * transformation.
 * 
 * 
 * Example 1:
 * Input: s = "aacecaaa"
 * Output: "aaacecaaa"
 * Example 2:
 * Input: s = "abcd"
 * Output: "dcbabcd"
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= s.length <= 5 * 10^4
 * s consists of lowercase English letters only.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string shortestPalindrome(string s) {
        string rev = s; 
        reverse(rev.begin(), rev.end());
        
        string newstr = s+"#"+rev;
        
        int len = 0;
        int i = 1;
        int n = newstr.size();
        vector<int> lenarr(n);
//         ananab#banana
        
        while(i<n){
            
            if(newstr[len]==newstr[i]){
                lenarr[i] = len+1; 
                len++;
                i++;
            }else{
                if(len!=0){
                    len = lenarr[len-1];
                }else{
                    lenarr[i] = 0;
                    i++;
                }
            }                            
        }
        // for(auto i: newstr){
        //     cout<<i<<"\t";
        // }
        // cout<<endl;
        // for(auto i: lenarr){
        //     cout<<i<<"\t";
        // }
        return rev.substr(0,s.size()-lenarr[n-1])+s;
    }
};
// @lc code=end

