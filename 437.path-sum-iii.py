# /*
#  * @lc app=leetcode id=437 lang=cpp
#  *
#  * [437] Path Sum III
#  *
#  * https://leetcode.com/problems/path-sum-iii/description/
#  *
#  * algorithms
#  * Medium (48.42%)
#  * Likes:    5097
#  * Dislikes: 323
#  * Total Accepted:    268.5K
#  * Total Submissions: 554.6K
#  * Testcase Example:  '[10,5,-3,3,2,null,11,3,-2,null,1]\n8'
#  *
#  * Given the root of a binary tree and an integer targetSum, return the number
#  * of paths where the sum of the values along the path equals targetSum.
#  * 
#  * The path does not need to start or end at the root or a leaf, but it must go
#  * downwards (i.e., traveling only from parent nodes to child nodes).
#  * 
#  * 
#  * Example 1:
#  * 
#  * 
#  * Input: root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
#  * Output: 3
#  * Explanation: The paths that sum to 8 are shown.
#  * 
#  * 
#  * Example 2:
#  * 
#  * 
#  * Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
#  * Output: 3
#  * 
#  * 
#  * 
#  * Constraints:
#  * 
#  * 
#  * The number of nodes in the tree is in the range [0, 1000].
#  * -10^9 <= Node.val <= 10^9
#  * -1000 <= targetSum <= 1000
#  * 
#  * 
#  */

# // @lc code=start
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
        
#pythonsolution        


