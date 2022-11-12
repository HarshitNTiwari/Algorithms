/*
Author: Harshit Tiwari
Date: 09-11-2022
https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/
*/

// T.C. : O(n)

class Solution {
public:
	void insertBST(TreeNode* &root, int val) {
		if (root == NULL) {
			root = new TreeNode(val);
			return;
		}
		TreeNode* temp = root;
		TreeNode* prev = NULL;
		while (temp != NULL) {
			prev = temp;
			if (temp->val < val)
				temp = temp->right;
			else
				temp = temp->left;
		}
		TreeNode* newNode = new TreeNode(val);
		if (prev->val > val)
			prev->left = newNode;
		else
			prev->right = newNode;
		return;
	}
	TreeNode* bstFromPreorder(vector<int>& preorder) {
		TreeNode* root = NULL;
		for (int i = 0; i < preorder.size(); i++) {
			insertBST(root, preorder[i]);
		}
		return root;
	}
};