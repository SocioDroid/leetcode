/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
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
#include <bits/stdc++.h>
#include<queue>
struct CompareNode {
    bool operator()(ListNode* n1, ListNode* n2) {
        return n1->val > n2->val;
    }
};
class Solution {
public:
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0)
            return NULL;
        if(lists.size()==1)
            return lists[0];
        
        priority_queue<ListNode*, vector<ListNode*>, CompareNode> pq;
        
        for (auto i: lists)
            if(i)
                pq.push(i);
        
        // showpq(pq);
        ListNode* ans = new ListNode();
        ListNode* p = ans;
        
        while(!pq.empty()){
            ListNode* n = pq.top();
            pq.pop();
            p->next = n;
            p = p->next;
            if(n->next){
                pq.push(n->next);   
            }            
        }
        return ans->next;
    }       
};
// @lc code=end

