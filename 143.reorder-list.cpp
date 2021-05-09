/*
 * @lc app=leetcode id=143 lang=cpp
 *
 * [143] Reorder List
 *
 * https://leetcode.com/problems/reorder-list/description/
 *
 * algorithms
 * Medium (41.40%)
 * Likes:    3135
 * Dislikes: 146
 * Total Accepted:    323.3K
 * Total Submissions: 780.9K
 * Testcase Example:  '[1,2,3,4]'
 *
 * You are given the head of a singly linked-list. The list can be represented
 * as:
 * 
 * 
 * L0 → L1 → … → Ln - 1 → Ln
 * 
 * 
 * Reorder the list to be on the following form:
 * 
 * 
 * L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
 * 
 * 
 * You may not modify the values in the list's nodes. Only nodes themselves may
 * be changed.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: head = [1,2,3,4]
 * Output: [1,4,2,3]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: head = [1,2,3,4,5]
 * Output: [1,5,2,4,3]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the list is in the range [1, 5 * 10^4].
 * 1 <= Node.val <= 1000
 * 
 * 
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    
    void reverse(ListNode* head, vector<ListNode*> *vect){
        
        if(head == NULL) return;
        
        reverse(head->next, vect);
        vect->push_back(head);
    }
    
    void reorderList(ListNode* head) {        
        vector<ListNode*> vect;
        reverse(head, &vect);
                
        ListNode *thead = head;
        ListNode *tnext;
        
        int i = 0, len = vect.size();
        
        if(len<=2) return;
        
        
        for(int i = 0; i<len/2; i++){
            tnext = thead->next;
            thead->next = vect[i];
            thead = thead->next;
            thead->next = tnext;
            thead = thead->next;
        }            
        thead->next = NULL;
    }
};
// @lc code=end

