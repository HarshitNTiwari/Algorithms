 /*
Author: Harshit Tiwari
Date: 09-08-2022
https://leetcode.com/problems/binary-tree-level-order-traversal/
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
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> traversal;
        queue<TreeNode*> q;
        
        if(root != NULL){
            vector<int> temp;
            temp.push_back(root->val);
            traversal.push_back(temp);
            q.push(root);
        }

        while(!q.empty()){
            int len = q.size();
            vector<int> temp;
            for(int i=0; i<len; i++){  //traversing until all the nodes of current level are pushed into temp
                TreeNode* tempNode = q.front();
                q.pop();
                if(tempNode->left != NULL){
                    temp.push_back(tempNode->left->val);
                    q.push(tempNode->left);
                }
                if(tempNode->right != NULL){
                    temp.push_back(tempNode->right->val);
                    q.push(tempNode->right);
                }
            }
            if(!temp.empty())
                traversal.push_back(temp);
        }
        
        return traversal;
    }
};