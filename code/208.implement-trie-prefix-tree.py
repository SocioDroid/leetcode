class Trie:
    
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.children = [None]*26
        self.isEndOfWord = False        

         
    def insert(self, word: str) -> None:
        """
        Inserts a word into the trie.
        """
        curr = self
        for x in word:
            if curr.children[ord(x)-ord('a')] == None:
                curr.children[ord(x)-ord('a')] = Trie()
            curr = curr.children[ord(x)-ord('a')] 
        curr.isEndOfWord = True

    def search(self, word: str) -> bool:
        """
        Returns if the word is in the trie.
        """
        curr = self
        for x in word:
            if not curr.children[ord(x)-ord('a')] == None:
                curr = curr.children[ord(x)-ord('a')]
            else:
                return False
        if curr.isEndOfWord:
            return True
        return False
        

    def startsWith(self, prefix: str) -> bool:
        """
        Returns if there is any word in the trie that starts with the given prefix.
        """
        curr = self
        for x in prefix:
            if not curr.children[ord(x)-ord('a')] == None:
                curr = curr.children[ord(x)-ord('a')]
            else:
                return False
        return True
            
        


# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)