/*
Author: Harshit Tiwari
Date: 08-11-2022
https://leetcode.com/problems/kth-smallest-element-in-a-bst/
*/

class Solution {
public:

	void inorder(TreeNode* root, vector<TreeNode*>& vec) {
		if (root == NULL)
			return;
		inorder(root->left, vec);
		vec.push_back(root);
		inorder(root->right, vec);
		return;
	}
	int kthSmallest(TreeNode* root, int k) {
		vector<TreeNode*> vec;
		inorder(root, vec);

		return vec[k - 1]->val;
	}
};