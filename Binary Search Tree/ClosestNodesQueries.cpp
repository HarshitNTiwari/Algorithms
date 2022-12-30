/*
Author: Harshit Tiwari
Date: 20-11-2022
https://leetcode.com/problems/closest-nodes-queries-in-a-binary-search-tree/
*/

class Solution {
public:
	void floorCeilBST(TreeNode* root, int key, int& floor, int& ceil) {
		while (root) {
			if (root->val == key) {
				ceil = root->val;
				floor = root->val;
				return;
			}

			if (key > root->val) {
				floor = root->val;
				root = root->right;
			}
			else {
				ceil = root->val;
				root = root->left;
			}
		}
		return;
	}

	vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
		vector<vector<int>> ans;
		for (int i = 0; i < queries.size(); i++) {
			int mini = -1; int maxi = -1;
			floorCeilBST(root, queries[i], mini, maxi);
			ans.push_back({mini, maxi});
		}
		return ans;
	}
};