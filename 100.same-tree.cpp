/*
 * @lc app=leetcode id=100 lang=cpp
 *
 * [100] Same Tree
 *
 * https://leetcode.com/problems/same-tree/description/
 *
 * algorithms
 * Easy (54.32%)
 * Likes:    3222
 * Dislikes: 87
 * Total Accepted:    719.9K
 * Total Submissions: 1.3M
 * Testcase Example:  '[1,2,3]\n[1,2,3]'
 *
 * Given the roots of two binary trees p and q, write a function to check if
 * they are the same or not.
 * 
 * Two binary trees are considered the same if they are structurally identical,
 * and the nodes have the same value.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: p = [1,2,3], q = [1,2,3]
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: p = [1,2], q = [1,null,2]
 * Output: false
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: p = [1,2,1], q = [1,1,2]
 * Output: false
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in both trees is in the range [0, 100].
 * -10^4 <= Node.val <= 10^4
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
    
    
    bool traverse(TreeNode* p, TreeNode* q){                
        if(p == NULL && q == NULL){            
            
            return true;
        }
        
        if(p == NULL || q == NULL){
            
            return false;
        }
        
        if(p->val == q->val){
            return traverse(p->left, q->left) && traverse(p->right, q->right);            
        }else{
            return false;
        }                
    }
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return traverse(p, q);
        
    }
};
// @lc code=end

