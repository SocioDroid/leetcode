/*
 * @lc app=leetcode id=647 lang=cpp
 *
 * [647] Palindromic Substrings
 *
 * https://leetcode.com/problems/palindromic-substrings/description/
 *
 * algorithms
 * Medium (62.80%)
 * Likes:    4318
 * Dislikes: 138
 * Total Accepted:    285.5K
 * Total Submissions: 454.2K
 * Testcase Example:  '"abc"'
 *
 * Given a string s, return the number of palindromic substrings in it.
 * 
 * A string is a palindrome when it reads the same backward as forward.
 * 
 * A substring is a contiguous sequence of characters within the string.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "abc"
 * Output: 3
 * Explanation: Three palindromic strings: "a", "b", "c".
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "aaa"
 * Output: 6
 * Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 1000
 * s consists of lowercase English letters.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool isPal(int i, int j, string &s){
        if(i >= j)
            return true;
        return s[i] == s[j] && isPal(i+1, j-1, s);
    }
    

    int countSubstrings(string s) {
        int cnt = s.length();
        for(int i = 0; i < s.length(); i++){
            for(int j = i+1; j < s.length(); j++){
                if(isPal(i, j, s))
                    cnt += 1;
            }
        }
        return cnt;
    }
};


// ----------------------------------
class Solution {
public:
    
    bool isPalindrome(string s){
        // cout<<s<<endl;
        int i = 0, j = s.size()-1;
        while(j>i){
            if(s[i++]!=s[j--]){                
                return false;
            }
        }
        
        return true;
    }
    int countSubstrings(string s) {
        int n = s.size();
        int count = 0;
        for (int i = 0; i < n; i++)
            for (int len = 1; len <= n - i; len++){
                if(isPalindrome(s.substr(i,len)))
                    count++;
            }
        return count;
    }
};
// @lc code=end

