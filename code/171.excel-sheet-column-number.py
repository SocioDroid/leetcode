class Solution:
    def titleToNumber(self, s: str) -> int:
        num = 0
        
        def asci(c):
            return ord(c)-64
        
        for i in range(len(s)):
            num = 26*num + asci(s[i])
        
        return num