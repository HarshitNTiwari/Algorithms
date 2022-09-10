/*
Author: Harshit Tiwari
Date: 10-09-2022
https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        stack<Node*> st;
        Node* curr = head;
        while (curr != NULL) {
            if (curr->child != NULL) {
                if (curr->next != NULL)
                    st.push(curr->next);
                curr->next = curr->child;
                curr->child = NULL;
                Node* temp = curr;
                curr = curr->next;
                curr->prev = temp;
                continue;
            }
            if (curr->next == NULL) {
                if (!st.empty()) {
                    Node* previ = st.top();
                    st.pop();
                    curr->next = previ;
                    previ->prev = curr;
                }
                else {
                    break;
                }
            }
            curr = curr->next;
        }
        return head;
    }
};