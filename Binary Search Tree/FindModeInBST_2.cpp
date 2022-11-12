/*
Author: Harshit Tiwari
Date: 11-11-2022
https://leetcode.com/problems/find-mode-in-binary-search-tree/
*/

// T.C: O(n) S.C: O(1)

class Solution {
public:
	int currFreq = 0, maxFreq = 0; int prev = INT_MIN;

	// To find the max freq:
	void inorder(TreeNode* root) {
		if (!root)
			return;
		inorder(root->left);
		if (prev == root->val)
			currFreq++;
		else
			currFreq = 1;
		prev = root->val;
		maxFreq = max(currFreq, maxFreq);
		inorder(root->right);
		return;
	}

	// To find the val with maxFreq:
	void findMax(TreeNode* root, vector<int>& ans) {
		if (!root)
			return;
		findMax(root->left, ans);
		if (prev == root->val)
			currFreq++;
		else
			currFreq = 1;
		if (currFreq == maxFreq)
			ans.push_back(root->val);
		prev = root->val;
		findMax(root->right, ans);
		return;
	}
	vector<int> findMode(TreeNode* root) {
		inorder(root);
		currFreq = 0; prev = INT_MIN;
		vector<int> ans;
		findMax(root, ans);
		return ans;
	}
};