/*
Author: Harshit Tiwari
Date: 08-11-2022
https://leetcode.com/problems/delete-node-in-a-bst/
*/

class Solution {
public:
	TreeNode* deleteNode(TreeNode* root, int key) {
		TreeNode* tempNode = root;
		TreeNode* prev = NULL;
		while (root != NULL && root->val != key) {
			prev = root;
			if (root->val > key)
				root = root->left;
			else
				root = root->right;
		}
		if (root == NULL)
			return tempNode;
		if (prev) {
			if (root->val < prev->val) {
				if (root->left != NULL) {
					TreeNode* temp = root->left;
					TreeNode* parent;
					while (temp != NULL) {
						parent = temp;
						temp = temp->right;
					}
					parent->right = root->right;
					root->right = NULL;
					prev->left = root->left;
					root->left = NULL;
				}
				else {
					prev->left = root->right;
				}
			}
			else {
				if (root->right != NULL) {
					TreeNode* temp = root->right;
					TreeNode* parent;
					while (temp != NULL) {
						parent = temp;
						temp = temp->left;
					}
					parent->left = root->left;
					root->left = NULL;
					prev->right = root->right;
					root->right = NULL;
				}
				else {
					prev->right = root->left;
				}
			}
		}
		else {
			if (root->right == NULL && root->left != NULL)
				return root = root->left;
			else if (root->left == NULL && root->right != NULL)
				return root = root->right;
			else if (root->left == NULL && root->right == NULL)
				return root = NULL;
			TreeNode* temp = root->right;
			TreeNode* parent;
			while (temp != NULL) {
				parent = temp;
				temp = temp->left;
			}
			parent->left = root->left;
			root->left = NULL;
			root = root->right;
			tempNode = root;
		}
		return tempNode;
	}
};