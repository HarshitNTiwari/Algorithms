/*
Author: Harshit Tiwari
Date: 06-07-2022
https://leetcode.com/problems/minimum-falling-path-sum/
*/

// Tabulation (bottom up) DP approach   +   Space Optimization
// SC: O(n)  (using just two 1D arrays)

class Solution {
private:
	int solve(int n, vector<vector<int>>& matrix, vector<int>& dp) {
		//initialization:
		for (int col = 1; col <= n; col++) {
			dp[col - 1] = matrix[0][col - 1];
		}

		//filling up of dp matrix:
		for (int row = 2; row <= n; row++) {
			vector<int> temp(n, INT_MAX);
			for (int col = 1; col <= n; col++) {
				if (col == 1)
					temp[col - 1] = matrix[row - 1][col - 1] + min(dp[col - 1] , dp[col]);
				else if (col == n)
					temp[col - 1] = matrix[row - 1][col - 1] + min(dp[col - 1] , dp[col - 2]);
				else
					temp[col - 1] = matrix[row - 1][col - 1] + min(dp[col - 1], min(dp[col], dp[col - 2]));
			}
			dp = temp;
		}

		int ans = INT_MAX;
		for (int col = 1; col <= n; col++) {
			ans = min(ans, dp[col - 1]);
		}
		return ans;
	}

public:
	int minFallingPathSum(vector<vector<int>>& matrix) {
		int n = matrix.size();
		int ans = INT_MAX;
		vector<int> dp(n, INT_MAX); //1D array to store answers of previous row

		return solve(n, matrix, dp);
	}
};