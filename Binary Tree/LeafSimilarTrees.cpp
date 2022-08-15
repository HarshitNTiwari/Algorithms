/*
Author: Harshit Tiwari
Date: 11-08-2022
https://leetcode.com/problems/leaf-similar-trees/
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
    void solve(TreeNode* root, vector<int>& seq){
        if(root == NULL)
            return;
        if(root->left == NULL && root->right == NULL){ //whenever root node is encountered
            seq.push_back(root->val);
            return; 
        }
        solve(root->left, seq);
        solve(root->right, seq);
        return;
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> seq1;
        vector<int> seq2;
        
        solve(root1, seq1);
        solve(root2, seq2);
        
        return seq1 == seq2;
    }
};