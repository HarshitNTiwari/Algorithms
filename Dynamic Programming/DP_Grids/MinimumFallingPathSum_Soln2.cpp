/*
Author: Harshit Tiwari
Date: 06-07-2022
https://leetcode.com/problems/minimum-falling-path-sum/
*/

// Tabulation (bottom up) DP approach
// SC: O(n*n)

class Solution {
private:
	int solve(int n, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
		//initialization:
		for (int col = 1; col <= n; col++) {
			dp[0][col - 1] = matrix[0][col - 1];
		}

		//filling up of dp matrix:
		for (int row = 2; row <= n; row++) {
			for (int col = 1; col <= n; col++) {
				if (col == 1)
					dp[row - 1][col - 1] = matrix[row - 1][col - 1] + min(dp[row - 2][col - 1] , dp[row - 2][col]);
				else if (col == n)
					dp[row - 1][col - 1] = matrix[row - 1][col - 1] + min(dp[row - 2][col - 1] , dp[row - 2][col - 2]);
				else
					dp[row - 1][col - 1] = matrix[row - 1][col - 1] + min(dp[row - 2][col - 1], min(dp[row - 2][col], dp[row - 2][col - 2]));
			}
		}

		//returning minimum from the last row:
		int ans = INT_MAX;
		for (int col = 1; col <= n; col++) {
			ans = min(ans, dp[n - 1][col - 1]);
		}
		return ans;
	}

public:
	int minFallingPathSum(vector<vector<int>>& matrix) {
		int n = matrix.size();
		int ans = INT_MAX;
		vector<vector<int>> dp(n, vector<int>(n, INT_MAX));

		return solve(n, matrix, dp);
	}
};