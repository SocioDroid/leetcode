# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def pathSum(self, root: TreeNode, sum: int) -> List[List[int]]:
        paths = list()
        self.findPath(root, sum, list(), paths)
        return paths
    
    def findPath(self, root, sum, current, paths):
        if root == None:
            return
        
        current.append(root.val)
        if root.val == sum and root.left == None and root.right == None:
            paths.append(current)
            return
        
        self.findPath(root.left, sum - root.val, list(current), paths)
        self.findPath(root.right, sum - root.val, list(current), paths)
            
        