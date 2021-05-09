/*
 * @lc app=leetcode id=111 lang=cpp
 *
 * [111] Minimum Depth of Binary Tree
 *
 * https://leetcode.com/problems/minimum-depth-of-binary-tree/description/
 *
 * algorithms
 * Easy (40.02%)
 * Likes:    2391
 * Dislikes: 822
 * Total Accepted:    555.5K
 * Total Submissions: 1.4M
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, find its minimum depth.
 * 
 * The minimum depth is the number of nodes along the shortest path from the
 * root node down to the nearest leaf node.
 * 
 * Note: A leaf is a node with no children.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [3,9,20,null,null,15,7]
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = [2,null,3,null,4,null,5,null,6]
 * Output: 5
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the tree is in the range [0, 10^5].
 * -1000 <= Node.val <= 1000
 * 
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    TreeNode* help(int &rootidx, int instart, int inend, vector<int>& preorder, vector<int>& inorder){
        
        if(instart>inend || rootidx>preorder.size()-1) return NULL;
        
        TreeNode* root = new TreeNode(preorder[rootidx]);
        
        int inidx = instart;
        
        while(preorder[rootidx] != inorder[inidx]) inidx++;
        
        rootidx++;
        
        root->left = help(rootidx, instart, inidx-1, preorder, inorder);
        root->right = help(rootidx, inidx+1, inend, preorder, inorder);
        
        return root;
                
    }        
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        int rootidx = 0;
        return help(rootidx,0,inorder.size()-1, preorder, inorder);
        
    }
};
// @lc code=end

