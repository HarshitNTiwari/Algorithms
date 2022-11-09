/*
Author: Harshit Tiwari
Date: 08-11-2022
https://www.codingninjas.com/codestudio/problems/floor-from-bst_920457
*/


int floorInBST(TreeNode<int> * root, int X)
{
	int ceil = -1;
	while (root != NULL) {
		if (root->val == X)
			return root->val;
		if (root->val > X)
			root = root->left;
		else if (root->val < X) {
			ceil = root->val;
			root = root->right;
		}
	}
	return ceil;
}