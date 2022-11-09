/*
Author: Harshit Tiwari
Date: 09-11-2022
https://leetcode.com/problems/validate-binary-search-tree/
*/

class Solution {
public:
	bool validBST(TreeNode* root, long max, long min) {
		if (root == NULL)
			return true;
		if (root->val >= max || root->val <= min)
			return false;
		bool validLeft = validBST(root->left, root->val, min);
		bool validRight = validBST(root->right, max, root->val);

		return validLeft && validRight;
	}
	bool isValidBST(TreeNode* root) {
		return validBST(root, LONG_MAX, LONG_MIN);
	}
};