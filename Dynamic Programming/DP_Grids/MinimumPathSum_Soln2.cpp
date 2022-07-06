/*
Author: Harshit Tiwari
Date: 05-07-2022
https://leetcode.com/problems/minimum-path-sum/
*/

// Tabulation (bottom up) DP approach

class Solution {
private:
	int solve(int m, int n, vector<vector<int>>& grid, vector<vector<int>>& dp) {
		//initialization of DP matrix:
		dp[0][0] = grid[0][0];
		for (int row = 1; row < m; row++) {  //for 1st column
			dp[row][0] = grid[row][0] + dp[row - 1][0];
		}
		for (int col = 1; col < n; col++) {  //for 1st row
			dp[0][col] = grid[0][col] + dp[0][col - 1];
		}

		//filling up the DP matrix
		for (int row = 1; row < m; row++) {
			for (int col = 1; col < n; col++) {
				dp[row][col] = grid[row][col] + min(dp[row - 1][col] , dp[row][col - 1]);
			}
		}
		return dp[m - 1][n - 1];
	}

public:
	int minPathSum(vector<vector<int>>& grid) {
		int m = grid.size();
		int n = grid[0].size();
		vector<vector<int>> dp(m, vector<int>(n, -1));
		return solve(m, n, grid, dp);
	}
};