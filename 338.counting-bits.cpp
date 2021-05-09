/*
 * @lc app=leetcode id=338 lang=cpp
 *
 * [338] Counting Bits
 *
 * https://leetcode.com/problems/counting-bits/description/
 *
 * algorithms
 * Medium (70.70%)
 * Likes:    3883
 * Dislikes: 209
 * Total Accepted:    354.3K
 * Total Submissions: 501K
 * Testcase Example:  '2'
 *
 * Given an integer num, return an array of the number of 1's in the binary
 * representation of every number in the range [0, num].
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: num = 2
 * Output: [0,1,1]
 * Explanation:
 * 0 --> 0
 * 1 --> 1
 * 2 --> 10
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: num = 5
 * Output: [0,1,1,2,1,2]
 * Explanation:
 * 0 --> 0
 * 1 --> 1
 * 2 --> 10
 * 3 --> 11
 * 4 --> 100
 * 5 --> 101
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= num <= 10^5
 * 
 * 
 * 
 * Follow up:
 * 
 * 
 * It is very easy to come up with a solution with run time O(32n). Can you do
 * it in linear time O(n) and possibly in a single pass?
 * Could you solve it in O(n) space complexity?
 * Can you do it without using any built-in function (i.e., like
 * __builtin_popcount in C++)?
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> countBits(int num) {
        
        vector<int> ans = {0};
        int n = 1;
        while(n <= num){
            int count= 0;
            if(n%2){
                // ODD
                count = 1+ans[n/2];
            }
            else{
                count = ans[n/2];
            }
            ans.push_back(count);
            n+=1;
        }
        
        return ans;

        
//         int n = 1;
//         while(n <= num){
//             int temp = n;
//             int count= 0;
//             while(temp){
//                 if(temp&1) count++;
//                 temp = temp >> 1;
//             }
//             ans.push_back(count);
//             n+=1;
//         }
        
//         return ans;
    }
};
// @lc code=end

