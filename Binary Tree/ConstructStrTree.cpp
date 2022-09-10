/*
Author: Harshit Tiwari
Date: 27-08-2022
https://leetcode.com/problems/construct-string-from-binary-tree/
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
	string ans;
	void solve(TreeNode* root) {
		string s = to_string(root->val);
		ans += s;
		if (root->left == NULL && root->right == NULL)
			return;
		if (root->left == NULL && root->right != NULL) {
			ans += "()";
			ans.push_back('(');
			solve(root->right);
			ans.push_back(')');
		}
		else if (root->left != NULL && root->right == NULL) {
			ans.push_back('(');
			solve(root->left);
			ans.push_back(')');
		}
		else if (root->left != NULL && root->right != NULL) {
			ans.push_back('(');
			solve(root->left);
			ans.push_back(')');
			ans.push_back('(');
			solve(root->right);
			ans.push_back(')');
		}
		return;
	}
public:
	string tree2str(TreeNode* root) {
		solve(root);
		return ans;
	}
};