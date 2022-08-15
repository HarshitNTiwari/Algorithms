/*
Author: Harshit Tiwari
Date: 09-08-2022
https://leetcode.com/problems/balanced-binary-tree/
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
    
    bool checkBalanced(TreeNode* root){
        return (abs(getHeight(root->left) - getHeight(root->right)) <= 1);
    }
public:
    bool isBalanced(TreeNode* root) {
        if(root!=NULL){
            if(checkBalanced(root))
                return (isBalanced(root->left) && isBalanced(root->right));
            else 
                return false;
        }
        return true;
    }
};