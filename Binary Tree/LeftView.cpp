 /*
Author: Harshit Tiwari
Date: 09-08-2022
https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1
*/


/* A binary tree node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */
 
void solve(Node* root, vector<int>& leftview, int currdepth, int& depth){
    if(root != NULL){
        if(currdepth > depth){
            depth = currdepth;
            leftview.push_back(root->data);
        }
        currdepth++;
            
        solve(root->left, leftview, currdepth, depth);
        solve(root->right, leftview, currdepth, depth);
    }
    return;
}
 

//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
    vector<int> leftview;
    
    int depth = 0;
    int currdepth = 1;
    
    solve(root, leftview, currdepth, depth);

    return leftview;
}
