class Solution:
    def threeConsecutiveOdds(self, arr: List[int]) -> bool:
        oddcount = 0
        for x in arr:
            if x%2 != 0:
                oddcount += 1
            else:
                oddcount = 0
            
            if oddcount == 3 :
                return True 
        return False