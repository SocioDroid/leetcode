import math
class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        row = [0]*(rowIndex+1)
        row[0] = 1
        row[rowIndex] = 1
        
        for k in range(1,math.ceil((rowIndex+1)/2)):
            temp = round(row[k-1]*((rowIndex+1-k)/k))
            row[k] = temp
            row[rowIndex-k] = temp
            # print(row)
        
        return row
            
        