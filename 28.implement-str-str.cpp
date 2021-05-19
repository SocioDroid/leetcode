/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Implement strStr()
 *
 * https://leetcode.com/problems/implement-strstr/description/
 *
 * algorithms
 * Easy (35.45%)
 * Likes:    2373
 * Dislikes: 2402
 * Total Accepted:    883.6K
 * Total Submissions: 2.5M
 * Testcase Example:  '"hello"\n"ll"'
 *
 * Implement strStr().
 * 
 * Return the index of the first occurrence of needle in haystack, or -1 if
 * needle is not part of haystack.
 * 
 * Clarification:
 * 
 * What should we return when needle is an empty string? This is a great
 * question to ask during an interview.
 * 
 * For the purpose of this problem, we will return 0 when needle is an empty
 * string. This is consistent to C's strstr() and Java's indexOf().
 * 
 * 
 * Example 1:
 * Input: haystack = "hello", needle = "ll"
 * Output: 2
 * Example 2:
 * Input: haystack = "aaaaa", needle = "bba"
 * Output: -1
 * Example 3:
 * Input: haystack = "", needle = ""
 * Output: 0
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= haystack.length, needle.length <= 5 * 10^4
 * haystack and needle consist of only lower-case English characters.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int strStr(string haystack, string needle) {
        // if needle is empty return 0
        // if needle return index of first occurence
        // else -1
        
        if(needle.size()==0)
            return 0;
        
        int j =0;
        int index = -1;
        for(int i = 0; i<haystack.size(); i++){                    
            if(haystack[i] == needle[j]){   
                // cout<<"i:"<<i<<"\tj:"<<j<<endl;
                if(j==needle.size()-1)
                    return i-j;
                j++;
            }else if(j){
                i = i-j;
                j = 0;                
            }                                    
        }                            
        return -1;
        
    }
};
// @lc code=end

