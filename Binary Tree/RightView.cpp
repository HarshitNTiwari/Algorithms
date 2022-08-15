 /*
Author: Harshit Tiwari
Date: 09-08-2022
https://leetcode.com/problems/binary-tree-right-side-view/
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
    void solve(TreeNode* root, vector<int>& rightView, int currdepth, int& depth){
        if(root != NULL){
            if(currdepth > depth){
                depth = currdepth;
                rightView.push_back(root->val);
            }
            currdepth++;
            solve(root->right, rightView, currdepth, depth);
            solve(root->left, rightView, currdepth, depth);
        }
        return;
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> rightView;
        
        int depth = 0;
        int currdepth = 1;
        
        solve(root, rightView, currdepth, depth);
        
        return rightView;
    }
};