/*
Author: Harshit Tiwari
Date: 09-11-2022
https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/
*/

// T.C.: O(n)

class Solution {
public:
	TreeNode* insertBST(vector<int>& preorder, int& i, int max) {
		if (i == preorder.size() || preorder[i] > max)
			return NULL;
		TreeNode* root = new TreeNode(preorder[i]);
		i++;
		root->left = insertBST(preorder, i, root->val);
		root->right = insertBST(preorder, i, max);
		return root;
	}
	TreeNode* bstFromPreorder(vector<int>& preorder) {
		int i = 0;
		return insertBST(preorder, i, INT_MAX);
	}
};