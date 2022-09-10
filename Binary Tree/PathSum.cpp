
/*
Author: Harshit Tiwari
Date: 26-08-2022
https://leetcode.com/problems/path-sum/
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
	bool ans = false;
	bool solve(TreeNode* root, int targetSum, int currSum) {
		if (root->left == NULL && root->right == NULL) {
			currSum += root->val;
			if (currSum == targetSum) {
				return ans = true;
			}
		}

		currSum += root->val;
		bool a , b;
		if (root->left != NULL)
			a = solve(root->left, targetSum, currSum);
		if (root->right != NULL)
			b = solve(root->right, targetSum, currSum);
		return ans = ans || a || b;
	}
public:
	bool hasPathSum(TreeNode* root, int targetSum) {
		if (root == NULL)
			return false;
		solve(root, targetSum, 0);
		return ans;
	}
};