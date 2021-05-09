/*
 * @lc app=leetcode id=69 lang=cpp
 *
 * [69] Sqrt(x)
 *
 * https://leetcode.com/problems/sqrtx/description/
 *
 * algorithms
 * Easy (35.56%)
 * Likes:    1967
 * Dislikes: 2358
 * Total Accepted:    723.4K
 * Total Submissions: 2M
 * Testcase Example:  '4'
 *
 * Given a non-negative integer x, compute and return the square root of x.
 * 
 * Since the return type is an integer, the decimal digits are truncated, and
 * only the integer part of the result is returned.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: x = 4
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: x = 8
 * Output: 2
 * Explanation: The square root of 8 is 2.82842..., and since the decimal part
 * is truncated, 2 is returned.
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= x <= 2^31 - 1
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int mySqrt(int x) {
        int tx = x;
        
        long long start = 1, end = x;
        
        if(x < 2) return x;
        while(start < end){
            
            long long mid = (start+end)/2;
            
            // cout<<mid<<endl;
            
            if(mid*mid == x){
                
                return mid;
            }
            else if( mid*mid > x){
                end = mid;
            }
            else if( mid*mid < x){
                start = mid+1;                   
            } 
        }
        return start - 1;
    }
};
// @lc code=end

