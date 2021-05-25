class Solution:
    def hIndex(self, citations: List[int]) -> int:
        citations.sort()
        n = len(citations)        
        i = 1
        while i <= n:
            if citations[n-i] < i :
                break
            i+=1
        return i-1