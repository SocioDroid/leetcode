class Solution:
    def isPowerOfFour(self, num: int) -> bool:
        if num <= 0:
            return False
        return math.pow(4,int(math.log(num,4))) == num
                

        