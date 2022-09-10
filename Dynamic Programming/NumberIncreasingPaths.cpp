/*
Author: Harshit Tiwari
Date: 17-08-2022
https://leetcode.com/problems/number-of-increasing-paths-in-a-grid/
*/

class Solution {
	int solve(vector<vector<int>>& arr, int i, int j, vector<vector<long>>& dp) {
		int m = arr.size();
		int n = arr[0].size();

		if (dp[i][j] != -1)
			return dp[i][j];

		vector<int> rowNbr = {1, -1, 0, 0};
		vector<int> colNbr = {0, 0, 1, -1};

		long ans = 0;
		for (int k = 0; k < 4; k++) {
			if ((i + rowNbr[k]) < 0 || (j + colNbr[k]) < 0 || (i + rowNbr[k]) > (m - 1) || (j + colNbr[k]) > (n - 1))
				continue;
			if (arr[i + rowNbr[k]][j + colNbr[k]] > arr[i][j]) {
				ans += solve(arr, i + rowNbr[k], j + colNbr[k], dp);
			}
		}
		return dp[i][j] = (1 + ans) % M;
	}
public:
	int M = 1e9 + 7;
	int countPaths(vector<vector<int>>& grid) {
		int m = grid.size();
		int n = grid[0].size();

		if (m == 1 && n == 1)
			return 1;

		vector<vector<long>> dp(m, vector<long>(n, -1));
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				solve(grid, i, j, dp);
			}
		}
		long int ans  = 0;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				ans += dp[i][j];
			}
		}
		return (ans) % M;
	}
};