class Solution:
    sidx = -1
    eidx = -1
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        self.binary_search(nums,0,len(nums)-1, target)
        return [self.sidx, self.eidx]
    
    def binary_search(self, num, start, end, target):
        
        while start <= end:
            
            mid = start + (end-start) // 2
            
            if num[mid] == target:
                if mid == 0:
                    self.sidx = mid
                    if self.eidx != -1:
                        return
                elif num[mid-1] != target:
                    self.sidx = mid
                    if self.eidx != -1:
                        return            
                else:                    
                    self.binary_search(num,start, mid-1, target)
                
                if mid == len(num)-1:
                    self.eidx = mid
                    if self.sidx != -1:
                        return
                elif num[mid+1] != target:
                    # print("End", mid)
                    self.eidx = mid
                    if self.sidx != -1:
                        return
                else:                    
                    self.binary_search(num,mid+1, end, target)
            
            if num[mid] > target:
                end = mid-1
            else:
                start = mid+1
                
        return
                