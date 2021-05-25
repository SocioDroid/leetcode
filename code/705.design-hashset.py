class MyHashSet:
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.hset = set()
        

    def add(self, key: int) -> None:        
        self.hset.add(key)

    def remove(self, key: int) -> None:    
        if self.contains(key):
            self.hset.remove(key)

    def contains(self, key: int) -> bool:      
        return key in self.hset
            
        


# Your MyHashSet object will be instantiated and called as such:
# obj = MyHashSet()
# obj.add(key)
# obj.remove(key)
# param_3 = obj.contains(key)