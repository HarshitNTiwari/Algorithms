/*
Author: Harshit Tiwari
Date: 06-07-2022
https://leetcode.com/problems/minimum-falling-path-sum/
*/

// Recursion + Memoization (Top Down) DP approach.
// SC: O(n*n) (for DP matrix) + O(n) (for recursion stack space)

class Solution {
private:
	int solve(int row, int col, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
		int n = matrix.size();
		//Base condition:
		if (row == 1)
			return dp[row - 1][col - 1] = matrix[row - 1][col - 1];

		if (dp[row - 1][col - 1] != INT_MAX)
			return dp[row - 1][col - 1];

		if (col == 1)
			return dp[row - 1][col - 1] = matrix[row - 1][col - 1] + min(solve(row - 1, col, matrix, dp), solve(row - 1, col + 1, matrix, dp));
		else if (col == n)
			return dp[row - 1][col - 1] = matrix[row - 1][col - 1] + min(solve(row - 1, col, matrix, dp), solve(row - 1, col - 1, matrix, dp));


		return dp[row - 1][col - 1] = matrix[row - 1][col - 1] + min(solve(row - 1, col, matrix, dp), min(solve(row - 1, col - 1, matrix, dp), solve(row - 1, col + 1, matrix, dp)));
	}

public:
	int minFallingPathSum(vector<vector<int>>& matrix) {
		int n = matrix.size();
		int ans = INT_MAX;
		vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
		if (n == 1) //if there's just 1 row
			return matrix[n - 1][n - 1];

		int row = n;
		//finding minimum from the last row of matrix:
		for (int col = 1; col <= n; col++) {
			if (col == 1)
				ans = min(ans, matrix[n - 1][col - 1] + min(solve(row - 1, col, matrix, dp), solve(row - 1, col + 1, matrix, dp)));
			else if (col == n)
				ans = min(ans, matrix[n - 1][col - 1] + min(solve(row - 1, col, matrix, dp), solve(row - 1, col - 1, matrix, dp)));
			else
				ans = min(ans, matrix[n - 1][col - 1] + min(solve(row - 1, col, matrix, dp), min(solve(row - 1, col - 1, matrix, dp), solve(row - 1, col + 1, matrix, dp))));
		}

		return ans;
	}
};