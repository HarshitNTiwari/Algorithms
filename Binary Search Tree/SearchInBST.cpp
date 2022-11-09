/*
Author: Harshit Tiwari
Date: 07-11-2022
https://leetcode.com/problems/search-in-a-binary-search-tree/
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
	TreeNode* searchBST(TreeNode* root, int val) {
		// performing a binary search
		while (root != NULL) {
			if (root->val == val)
				return root;
			else if (root->val < val)
				root = root->right;
			else
				root = root->left;
		}
		return root; //if the val isn't found, null is returned
	}
};