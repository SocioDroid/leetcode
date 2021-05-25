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
        
    int treesum(TreeNode* root, int sm){
        
        if(!root) return sm;
        
        sm = treesum(root->right, sm);
        
        root->val += sm;
        sm = root->val;
        
        return treesum(root->left, sm);            
    }
    TreeNode* bstToGst(TreeNode* root) {        
        treesum(root, 0);
        return root;        
    }
};