/*
Author: Harshit Tiwari
Date: 11-11-2022
https://leetcode.com/problems/find-mode-in-binary-search-tree/
*/

// T.C: O(n)   S.C: O(n)

class Solution {
public:
	void inorder(TreeNode* root, unordered_map<int, int>& mp) {
		if (!root)
			return;
		inorder(root->left, mp);
		mp[root->val]++;
		inorder(root->right, mp);
		return;
	}
	vector<int> findMode(TreeNode* root) {
		unordered_map<int, int> mp;
		inorder(root, mp);

		int maxFreq = -1;
		for (auto it : mp)
			if (it.second > maxFreq)
				maxFreq = it.second;

		vector<int> ans;
		for (auto it : mp)
			if (it.second == maxFreq)
				ans.push_back(it.first);

		return ans;
	}
};