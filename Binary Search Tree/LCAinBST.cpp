/*
Author: Harshit Tiwari
Date: 09-11-2022
https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
*/

class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		// if both p and q lie in left of root
		if (p->val < root->val && q->val < root->val)
			return lowestCommonAncestor(root->left, p, q);
		// if both p and q lie in right of root
		else if (p->val > root->val && q->val > root->val)
			return lowestCommonAncestor(root->right, p, q);
		// if they lie in opposite sides of root, then root is the LCA for them!
		return root;
	}
};