/*
Author: Harshit Tiwari
Date: 21-06-2022
https://leetcode.com/problems/middle-of-the-linked-list/
*/


// Finding middle of Linked list using fast and slow pointers

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
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast!=NULL){
            fast = fast->next;
            if(fast!=NULL)
                fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};