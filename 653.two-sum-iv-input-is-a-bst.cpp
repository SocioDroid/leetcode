/*
 * @lc app=leetcode id=653 lang=cpp
 *
 * [653] Two Sum IV - Input is a BST
 *
 * https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/
 *
 * algorithms
 * Easy (56.45%)
 * Likes:    2052
 * Dislikes: 155
 * Total Accepted:    192.4K
 * Total Submissions: 340.9K
 * Testcase Example:  '[5,3,6,2,4,null,7]\n9'
 *
 * Given the root of a Binary Search Tree and a target number k, return true if
 * there exist two elements in the BST such that their sum is equal to the
 * given target.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [5,3,6,2,4,null,7], k = 9
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = [5,3,6,2,4,null,7], k = 28
 * Output: false
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: root = [2,1,3], k = 4
 * Output: true
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: root = [2,1,3], k = 1
 * Output: false
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: root = [2,1,3], k = 3
 * Output: true
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the tree is in the range [1, 10^4].
 * -10^4 <= Node.val <= 10^4
 * root is guaranteed to be a valid binary search tree.
 * -10^5 <= k <= 10^5
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
    
    void inorder(TreeNode* root, vector<int> &vect){
        
        if(!root) return;
        
        inorder(root->left, vect);
        
        vect.push_back(root->val);
        
        inorder(root->right, vect);
        
    }
    
    bool findTarget(TreeNode* root, int k) {
        vector<int> vect;
        
        inorder(root, vect);
        
        int l=0, r=vect.size()-1;
        
        // for(auto i : vect) cout<<i<<endl;
        while(l<r){
            int sum = vect[l]+vect[r];
            // cout<< vect[l]<<" + "<<vect[r]<<" = "<<sum<<endl;
            if(sum==k)  return true;
            
            else if(sum > k) r--;
            
            else if(sum < k) l++;
        }
        return false;                
    }
};
// @lc code=end

