/*
Author: Harshit Tiwari
Date: 04-07-2022
https://leetcode.com/problems/unique-paths/
*/

// Tabulation (bottom up) DP approach
// TC: O(m*n);  SC: O(m*n) (for dp matrix)

class Solution {
private:
	int solve(int m, int n, vector<vector<int>>& dp) {
		//Initialization:
		for (int row = 0; row < m; row++)
			dp[row][0] = 1;
		for (int col = 0; col < n; col++)
			dp[0][col] = 1;

		if (dp[m - 1][n - 1] != -1)
			return dp[m - 1][n - 1];

		//Filling up the dp matrix
		for (int row = 1; row < m; row++) {
			for (int col = 1; col < n; col++) {
				dp[row][col] = dp[row - 1][col] + dp[row][col - 1];
			}
		}
		return dp[m - 1][n - 1];
	}

public:
	int uniquePaths(int m, int n) {
		vector<vector<int>> dp(m, vector<int>(n, -1));
		return solve(m, n, dp);
	}
};