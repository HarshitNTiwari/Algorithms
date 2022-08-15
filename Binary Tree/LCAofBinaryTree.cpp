/*
Author: Harshit Tiwari
Date: 12-08-2022
https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    bool findp (TreeNode* root, TreeNode* p){
        if(root == NULL)
            return false;
        if(root == p)
            return true;
        return findp(root->left, p) || findp(root->right, p);
    }
    bool findq (TreeNode* root, TreeNode* q){
        if(root == NULL)
            return false;
        if(root == q)
            return true;
        return findp(root->left, q) || findp(root->right, q);
    }
    void solve (TreeNode* root, TreeNode* p, TreeNode* q){
        if(root == NULL)
            return;
        if(findp(root, p) && findq(root, q))
            LCA = root;
        solve(root->left, p, q);
        solve(root->right, p, q);
        return;
    }
public:
    TreeNode* LCA = NULL;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        solve(root, p, q);
        return LCA;
    }
};