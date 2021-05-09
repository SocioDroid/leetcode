/*
 * @lc app=leetcode id=445 lang=cpp
 *
 * [445] Add Two Numbers II
 *
 * https://leetcode.com/problems/add-two-numbers-ii/description/
 *
 * algorithms
 * Medium (56.72%)
 * Likes:    2339
 * Dislikes: 199
 * Total Accepted:    237.9K
 * Total Submissions: 419.5K
 * Testcase Example:  '[7,2,4,3]\n[5,6,4]'
 *
 * You are given two non-empty linked lists representing two non-negative
 * integers. The most significant digit comes first and each of their nodes
 * contains a single digit. Add the two numbers and return the sum as a linked
 * list.
 * 
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: l1 = [7,2,4,3], l2 = [5,6,4]
 * Output: [7,8,0,7]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: l1 = [2,4,3], l2 = [5,6,4]
 * Output: [8,0,7]
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: l1 = [0], l2 = [0]
 * Output: [0]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in each linked list is in the range [1, 100].
 * 0 <= Node.val <= 9
 * It is guaranteed that the list represents a number that does not have
 * leading zeros.
 * 
 * 
 * 
 * Follow up: Could you solve it without reversing the input lists?
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
    
   ListNode* reverseList(ListNode* head) {
        
        ListNode *temp = NULL;
        ListNode *thead = head;
        
        while(thead!=NULL)
        {
            ListNode *next = thead->next;
            thead->next = temp;
            temp = thead;
            thead = next;
        }
        return temp;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {     
        
        l1 = reverseList(l1);
        l2 = reverseList(l2);
        bool carry = false;
        ListNode *templ2 = l2;
        ListNode *recentInserted;
        
        while(l1 -> next != NULL &&  l2 ->next != NULL){
            if(carry){
                l1->val +=carry;
                carry = false;
                
            }
            
            int sum = l1->val + l2->val;
            if (sum > 9){
                // cout<<"Sum is greater than 9: "<< sum<<endl;
                carry = true;
                sum = sum%10;
            }
            l2->val = sum;
                        
            l1 = l1->next;
            l2 = l2->next;
        }
        
        if(l1->next == NULL && l2->next == NULL){
            if(carry){
                l1->val +=carry;
                carry = false;                
            }
            int sum = l1->val + l2->val;
            if (sum > 9){                                
                sum = sum%10;
                l2->val = sum;
                l2->next = new ListNode(1);
            }
            else{
                l2->val = sum;
            }
            
        }
        else if(l1->next != NULL && l2->next == NULL){
          if(carry){
                l1->val +=carry;
                carry = false;                
            }
            int sum = l1->val + l2->val;
            if (sum > 9){                                
                sum = sum%10;
                l2->val = sum;
                carry = true;
            }
            else{
                l2->val = sum;
            }
            l1 = l1->next;
            
            // cout<<"Carrry:" << carry<<" "<<l1->val<<endl;
            while(l1 !=NULL){
                int sum2=l1->val;
                if(carry){
                    sum2 = l1->val+1;
                    if (sum2 > 9){                                
                        sum2 = sum2%10;                        
                        carry = true;
                    }else{
                        carry = false;
                    }
                }else{
                    l2->next = l1;
                    break;
                }
                    // cout<<"Sum : "<< sum2 <<endl;
                    l2->next = new ListNode(sum2);
                    l1 = l1->next;
                    l2 = l2->next;
                    recentInserted = l2;                    
            }
            // while(carry){
            //     int sum2 = 0;
            //     if(carry){
            //         sum2 = l1->val+1;
            //         if (sum2 > 9){                                
            //             sum2 = sum2%10;                        
            //             carry = true;
            //         }else{
            //             carry = false;
            //         }
            //     }
            //         l2->next = new ListNode(sum2);
            //         l1 = l1->next;
            //         l2 = l2->next;
            // }
        }else if(l1->next == NULL && l2->next != NULL){
          if(carry){
                l2->val +=carry;
                carry = false;                
            }
            int sum = l1->val + l2->val;
            if (sum > 9){                                
                sum = sum%10;
                l2->val = sum;
                carry = true;
            }
            else{
                l2->val = sum;
            }
            l2 = l2->next;
            
            while(l2 != NULL){
                int sum2 = l2->val;
                if(carry){
                    sum2 = l2->val+1;
                    if (sum2 > 9){                                
                        sum2 = sum2%10;                        
                        carry = true;
                    }else{
                        carry = false;
                    }
                }
                    recentInserted = l2;
                    l2->val = sum2;                
                    l2 = l2->next;
            }
        }
        
        if(carry){
            // cout<<"Here";
            recentInserted->next = new ListNode(1);
        }
        
        return reverseList(templ2);
    }
};
// @lc code=end

