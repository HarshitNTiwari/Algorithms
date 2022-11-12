/*
Author: Harshit Tiwari
Date: 10-11-2022
https://leetcode.com/problems/recover-binary-search-tree/
*/


// T.C.: O(n)

class Solution {
public:
	TreeNode* firstElement = NULL; // 1st element to be swapped
	TreeNode* secElement = NULL; // 2nd element to be swapped
	TreeNode* prev = NULL; // tracks the previous node in the inorder traversal

	// Doing inorder traversal
	void inorder(TreeNode* root) {
		if (root == NULL)
			return;

		traverse(root->left);

		if (firstElement == NULL && prev->val > root->val)
			firstElement = prev;
		if (firstElement != NULL && prev->val > root->val)
			secElement = root;

		prev = root; //making current node as previous

		traverse(root->right);
		return;
	}
	void recoverTree(TreeNode* root) {
		prev = new TreeNode(INT_MIN);
		inorder(root);
		swap(firstElement->val, secElement->val);
	}
};