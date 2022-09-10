/*
Author: Harshit Tiwari
Date: 26-08-2022
https://leetcode.com/problems/sum-root-to-leaf-numbers/
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
	vector<int> numbers;
	void solve(TreeNode* root, long num) {
		if (root->left == NULL && root->right == NULL) {
			num *= 10;
			num += root->val;
			numbers.push_back(num);
		}

		num *= 10;
		num += root->val;
		if (root->left != NULL) {
			solve(root->left, num);
		}
		if (root->right != NULL) {
			solve(root->right, num);
		}
	}
public:
	int sumNumbers(TreeNode* root) {
		solve(root, 0);
		int sum = 0;
		for (auto& i : numbers)
			sum += i;
		return sum;
	}
};