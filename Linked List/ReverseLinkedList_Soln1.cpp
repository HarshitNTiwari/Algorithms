/*
Author: Harshit Tiwari
Date: 25-07-2022
https://leetcode.com/problems/reverse-linked-list/
*/

// Iterative solution to reverse a Linked List

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
        if(head==NULL)
            return head;
        ListNode* curr = head;
        ListNode* temp = head->next;
        ListNode* temp2 = NULL;
        
        while(temp!=NULL){
            curr->next = temp2;
            temp2 = curr;
            curr = temp;
            temp = temp->next;
        }
        curr->next = temp2;
        return curr;
    }
};