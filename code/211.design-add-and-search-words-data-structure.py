import collections
class WordDictionary:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.word = collections.defaultdict(set)

    def addWord(self, word: str) -> None:
        """
        Adds a word into the data structure.
        """
        if word:
            self.word[len(word)].add(word)

    def search(self, word: str) -> bool:
        """
        Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter.
        """
        if '.' not in word:
            return word in self.word[len(word)]
        else:
            for x in self.word[len(word)]:
                for i, w in enumerate(word):
                    if x[i] !=  w and w != '.':
                        break
                else:
                    return True
            return False    
            
        


# Your WordDictionary object will be instantiated and called as such:
# obj = WordDictionary()
# obj.addWord(word)
# param_2 = obj.search(word)