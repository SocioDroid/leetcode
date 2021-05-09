/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
 *
 * https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
 *
 * algorithms
 * Medium (36.22%)
 * Likes:    5379
 * Dislikes: 309
 * Total Accepted:    869.8K
 * Total Submissions: 2.4M
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * Given the head of a linked list, remove the n^th node from the end of the
 * list and return its head.
 * 
 * Follow up: Could you do this in one pass?
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: head = [1,2,3,4,5], n = 2
 * Output: [1,2,3,5]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: head = [1], n = 1
 * Output: []
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: head = [1,2], n = 1
 * Output: [1]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the list is sz.
 * 1 <= sz <= 30
 * 0 <= Node.val <= 100
 * 1 <= n <= sz
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next == NULL) return NULL;
        if(head->next->next == NULL){
            if(n==1){
                head->next = NULL;
            }else{
                return head->next;    
            }
            return head;
        }
        ListNode *l = head;
        ListNode *r = head;
        
        int gap =0;
        int count = 0;
        while(r->next!=NULL){
            if(gap != n){
                r = r->next;
                gap++;
                cout<<"INCR GAP" << gap<<endl;
            }else{
                r = r->next;
                l = l-> next;
                cout<<"INCR L" << gap<<endl;
                
            }
            count ++;
        }
        cout<<"Count "<<count;
        if(l == head && count<n) head = head->next;        
        else l->next = l->next->next;
        return head;
    }
};
// @lc code=end

