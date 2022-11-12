/*
Author: Harshit Tiwari
Date: 10-11-2022
https://leetcode.com/problems/search-in-a-binary-search-tree/
*/

class Solution {
public:
	bool findTarget(TreeNode* root, int k) {
		unordered_set<int> uset; //set to keep track of the values in BST
		queue<TreeNode*> q;
		q.push(root);
		// traversing in level order manner
		while (!q.empty()) {
			TreeNode* front = q.front();
			q.pop();
			if (uset.find(k - (front->val)) != uset.end()) //if pair found, return true
				return true;
			uset.insert(front->val);
			if (front->left)
				q.push(front->left);
			if (front->right)
				q.push(front->right);
		}
		return false;
	}
};