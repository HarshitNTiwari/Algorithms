/*
Author: Harshit Tiwari
Date: 05-07-2022
https://leetcode.com/problems/minimum-path-sum/
*/

//Recursion + Memoization (Top Down) DP approach.

class Solution {
private:
	int solve(int m, int n, vector<vector<int>>& grid, vector<vector<int>>& dp) {
		if (m == 1 && n == 1)  //starting position
			return dp[0][0] = grid[0][0];
		if (m == 1)    //1st row
			return dp[m - 1][n - 1] = grid[m - 1][n - 1] + solve(m, n - 1, grid, dp);
		if (n == 1)    //1st column
			return dp[m - 1][n - 1] = grid[m - 1][n - 1] + solve(m - 1, n, grid, dp);

		if (dp[m - 1][n - 1] != -1)
			return dp[m - 1][n - 1];

		return dp[m - 1][n - 1] = grid[m - 1][n - 1] + min(solve(m - 1, n, grid, dp) , solve(m, n - 1, grid, dp));
	}

public:
	int minPathSum(vector<vector<int>>& grid) {
		int m = grid.size();
		int n = grid[0].size();
		vector<vector<int>> dp(m, vector<int>(n, -1));
		return solve(m, n, grid, dp);
	}
};

