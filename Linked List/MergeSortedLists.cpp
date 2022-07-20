/*
Author: Harshit Tiwari
Date: 19-07-2022
https://leetcode.com/problems/merge-two-sorted-lists/
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL)  //if list1 is empty
            return list2;
        if(list2 == NULL)  //if list2 is empty
            return list1;
        
        //Choosing the head by comparing the first nodes of both the list
        ListNode* head;
        if(list1->val < list2->val){
            head = list1;
            list1 = list1->next;
        }
        else{
            head = list2;
            list2 = list2->next;
        }
        
        //constructing the remaining merged list
        ListNode* curr = head;
        while(list1 != NULL && list2 != NULL){
            if(list1->val < list2->val){
                curr->next = list1;
                list1 = list1->next;
            }
            else{
                curr->next = list2;
                list2 = list2->next;
            }
            curr = curr->next;
        }
        
        //appending the remaining of the two lists if any
        if(list1 != NULL)
            curr->next = list1;
        if(list2 != NULL)
            curr->next = list2;
        
        return head;
    }
};