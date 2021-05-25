# Definition for a binary tree node.
# class TreeNode:
#     def _init_(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
import collections
class Solution:
    def verticalTraversal(self, root: TreeNode) -> List[List[int]]:
        
        dictionary = collections.defaultdict(list)
        def report(node,x,y,dictionary):
            dictionary[x].append((node.val,abs(y)))
            if node.left is not None:
                report(node.left,x-1,y-1,dictionary)
            if node.right is not None:
                report(node.right,x+1,y-1,dictionary)
        report(root,0,0,dictionary)
        # print(dictionary)
        def sort(a,b):
            print(a,b)
            if a[1]>b[1]:
                return a[0]
            elif b[1]>a[1]:
                return b[0]
            else:
                return min(a[0],b[0])
        final_report = []
        for i in sorted(dictionary.keys()):
            # print(dictionary[i])
            dictionary[i].sort(key = lambda x: (x[1],x[0]))
            temp = []
            for i in dictionary[i]:
                temp.append(i[0])
            final_report.append(temp)
        return final_report