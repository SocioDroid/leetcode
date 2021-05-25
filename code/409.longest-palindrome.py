from collections import Counter
class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: int
        """
        count = Counter(s)
        ans = 0
        odd = 0
        for i in count:
            if count[i] % 2 == 1:
                odd += 1
            ans += count[i] // 2 * 2
            
        if odd:
            return ans+1
        
        return ans
                
            
            
        
        