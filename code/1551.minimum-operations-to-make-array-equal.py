class Solution:
    def minOperations(self, n: int) -> int:
        # if n % 2 != 0:
        midelement = 2 * (n//2) + 1
        x = 0
        y = n-1
        result = 0
        for i in range(n//2):
            xval = 2*x+1
            yval = 2*y+1
            
            
            if xval < midelement:
                # print("x =", x)
                result += abs(xval-midelement)
                x += 1
                
            if yval > midelement:
                # print(" y = ", y)
                result += abs(yval-midelement)
                y = y - 1
                
        return (result // 2)
    
    
        # else:
        #     midelement = 2 * (n//2) + 1
        #     midelement2 = 2 * ((n//2)-1) + 1
        #     x = 0
        #     y = n-1
        #     result = 0
        #     result2 = 0
        #     for i in range(n//2):
        #         x = 2*x+1
        #         y = 2*y+1
        #         if x < midelement:
        #             result += abs(x-midelement)
        #             x += 1
        #         if y > midelement:
        #             result += abs(y-midelement)
        #             y -= 1
        #     return result // 2
            
        
        