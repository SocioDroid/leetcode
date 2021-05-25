# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    count = 0
    l = list()
    sum = 0
    def pathSum(self, root: TreeNode, sum: int) -> int:
        self.sum = sum
        self.findPath(root)
        return self.count
    
    def findPath(self,root):
        if root == None:
            return
        
        self.l.append(root.val)
        
        self.findPath(root.left)
        self.findPath(root.right)
        
        temp = 0
        for x in range(len(self.l)-1,-1,-1):
            temp += self.l[x]
            if temp == self.sum:
                self.count += 1
        
        self.l.pop(len(self.l)-1)        
        
        