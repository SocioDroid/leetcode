from itertools import combinations
class CombinationIterator(object):

    def __init__(self, characters, combinationLength):
        """
        :type characters: str
        :type combinationLength: int
        """
        self.iterator = 0
        self.lst = []
        for element in combinations(characters, combinationLength):             
            self.lst.append((''.join(list(element))))
        
        self.size = len(self.lst)
        
    def next(self):
        """
        :rtype: str
        """
        self.iterator += 1
        return self.lst[self.iterator-1]
        

    def hasNext(self):
        """
        :rtype: bool
        """
        return True if self.iterator < self.size else False
        


# Your CombinationIterator object will be instantiated and called as such:
# obj = CombinationIterator(characters, combinationLength)
# param_1 = obj.next()
# param_2 = obj.hasNext()