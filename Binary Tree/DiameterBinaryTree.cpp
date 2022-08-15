/*
Author: Harshit Tiwari
Date: 09-08-2022
https://leetcode.com/problems/diameter-of-binary-tree/
*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int getHeight(TreeNode* root){
        if(root!=NULL){
            return 1 + max(getHeight(root->left), getHeight(root->right));
        }
        return 0;
    }
    int ans = INT_MIN;
    void solve(TreeNode* root){
        if(root!=NULL){
            if(ans == INT_MIN){
                ans = getHeight(root->left) + getHeight(root->right);
            }
            int localans = getHeight(root->left) + getHeight(root->right);
            ans = max(ans, localans);
            solve(root->left);
            solve(root->right);
        }
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        solve(root);
        return ans == INT_MIN ? 0 : ans;
    }
};