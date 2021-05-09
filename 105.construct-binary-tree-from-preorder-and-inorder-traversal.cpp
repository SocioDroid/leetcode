/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
 *
 * https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
 *
 * algorithms
 * Medium (52.76%)
 * Likes:    5170
 * Dislikes: 130
 * Total Accepted:    492.4K
 * Total Submissions: 933.3K
 * Testcase Example:  '[3,9,20,15,7]\n[9,3,15,20,7]'
 *
 * Given two integer arrays preorder and inorder where preorder is the preorder
 * traversal of a binary tree and inorder is the inorder traversal of the same
 * tree, construct and return the binary tree.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
 * Output: [3,9,20,null,null,15,7]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: preorder = [-1], inorder = [-1]
 * Output: [-1]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= preorder.length <= 3000
 * inorder.length == preorder.length
 * -3000 <= preorder[i], inorder[i] <= 3000
 * preorder and inorder consist of unique values.
 * Each value of inorder also appears in preorder.
 * preorder is guaranteed to be the preorder traversal of the tree.
 * inorder is guaranteed to be the inorder traversal of the tree.
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

