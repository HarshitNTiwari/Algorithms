/*
Author: Harshit Tiwari
Date: 21-06-2022
https://leetcode.com/problems/middle-of-the-linked-list/
*/


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
        int size =0;
        ListNode* temp = head;
        while(temp != NULL){
            size++;
            temp = temp->next;
        }
        
        ListNode* ans = head;
        for(int i=1; i<(size/2)+1; i++){
            ans = ans->next;
        }
        return ans;
    }
};