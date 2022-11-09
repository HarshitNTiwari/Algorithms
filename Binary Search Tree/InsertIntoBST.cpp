/*
Author: Harshit Tiwari
Date: 08-11-2022
https://leetcode.com/problems/insert-into-a-binary-search-tree/
*/

class Solution {
public:
	TreeNode* insertIntoBST(TreeNode* root, int val) {
		if (!root) {
			root = new TreeNode(val);
			return root;
		}
		TreeNode* temp = root;
		TreeNode* prev = NULL;
		while (root != NULL) {
			prev = root;
			if (root->val > val)
				root = root->left;
			else
				root = root->right;
		}
		TreeNode* newNode = new TreeNode(val);
		if (prev->val > val)
			prev->left = newNode;
		else
			prev->right = newNode;
		return temp;
	}
};