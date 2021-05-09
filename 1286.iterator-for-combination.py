# /*
#  * @lc app=leetcode id=1286 lang=cpp
#  *
#  * [1286] Iterator for Combination
#  *
#  * https://leetcode.com/problems/iterator-for-combination/description/
#  *
#  * algorithms
#  * Medium (70.96%)
#  * Likes:    595
#  * Dislikes: 46
#  * Total Accepted:    39.9K
#  * Total Submissions: 56.3K
#  * Testcase Example:  '["CombinationIterator","next","hasNext","next","hasNext","next","hasNext"]\n[["abc",2],[],[],[],[],[],[]]'
#  *
#  * Design the CombinationIterator class:
#  * 
#  * 
#  * CombinationIterator(string characters, int combinationLength) Initializes
#  * the object with a string characters of sorted distinct lowercase English
#  * letters and a number combinationLength as arguments.
#  * next() Returns the next combination of length combinationLength in
#  * lexicographical order.
#  * hasNext() Returns true if and only if there exists a next combination.
#  * 
#  * 
#  * 
#  * Example 1:
#  * 
#  * 
#  * Input
#  * ["CombinationIterator", "next", "hasNext", "next", "hasNext", "next",
#  * "hasNext"]
#  * [["abc", 2], [], [], [], [], [], []]
#  * Output
#  * [null, "ab", true, "ac", true, "bc", false]
#  * 
#  * Explanation
#  * CombinationIterator itr = new CombinationIterator("abc", 2);
#  * itr.next();    // return "ab"
#  * itr.hasNext(); // return True
#  * itr.next();    // return "ac"
#  * itr.hasNext(); // return True
#  * itr.next();    // return "bc"
#  * itr.hasNext(); // return False
#  * 
#  * 
#  * 
#  * Constraints:
#  * 
#  * 
#  * 1 <= combinationLength <= characters.length <= 15
#  * All the characters of characters are unique.
#  * At most 10^4 calls will be made to next and hasNext.
#  * It's guaranteed that all calls of the function next are valid.
#  * 
#  * 
#  */

# // @lc code=start
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
        
#pythonsolution

# Your CombinationIterator object will be instantiated and called as such:
# obj = CombinationIterator(characters, combinationLength)
# param_1 = obj.next()
# param_2 = obj.hasNext()

# /**
#  * Your CombinationIterator object will be instantiated and called as such:
#  * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
#  * string param_1 = obj->next();
#  * bool param_2 = obj->hasNext();
#  */
# // @lc code=end

