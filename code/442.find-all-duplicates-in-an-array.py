class Solution:
    def findDuplicates(self, nums: List[int]) -> List[int]:
        l = []
        for n in nums:
            n = abs(n)
            if nums[n-1] > 0: nums[n-1] *= -1                
            else:
                l.append(n)
        return l
                
        