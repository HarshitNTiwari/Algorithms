/*
Author: Harshit Tiwari
Date: 20-07-2022
https://leetcode.com/problems/linked-list-cycle/
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// SC : O(n) as a Hash map is used.

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL)  // if LL is empty
            return false;
        unordered_map<ListNode*, bool> listmap;  //map to mark if a node has been visited

        while(head != NULL){
            if(listmap[head]==true)  //if the node has already been visited once i.e. cycle is present
                return true; 
            listmap[head]=true;  //marking the node as visited
            head = head->next;
        }
        return false;
    }
};