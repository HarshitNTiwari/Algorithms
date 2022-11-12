/*
Author: Harshit Tiwari
Date: 09-11-2022
https://leetcode.com/problems/search-in-a-binary-search-tree/
*/

class Solution {
public:
	bool searchBST(TreeNode* root, int val, int k) {

		while (root != NULL) {
			if (root->val == val && root->val != k / 2)
				return true;
			if (root->val < val)
				root = root->right;
			else
				root = root->left;
		}
		cout << "val: " << val << endl;
		return false;
	}

	bool findTarget(TreeNode* root, int k) {
		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty()) {
			TreeNode* front = q.front();
			q.pop();
			if (searchBST(root, k - (front->val), k))
				return true;
			if (front->left)
				q.push(front->left);
			if (front->right)
				q.push(front->right);
		}
		return false;
	}
};