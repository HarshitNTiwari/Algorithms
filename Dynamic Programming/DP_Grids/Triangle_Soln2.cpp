/*
Author: Harshit Tiwari
Date: 05-07-2022
https://leetcode.com/problems/triangle/
*/

// Tabulation (bottom up) DP approach

class Solution {
private:
	void solve(int m, vector<vector<int>>& triangle, vector<vector<int>>& dp) {
		for (int row = 1; row <= m; row++) {
			for (int col = 1; col <= row; col++) {
				if (row == 1 && col == 1)
					dp[row - 1][col - 1] = triangle[row - 1][col - 1];
				else if (col == 1)
					dp[row - 1][col - 1] = triangle[row - 1][col - 1] + dp[row - 2][col - 1];
				else if (col == row)
					dp[row - 1][col - 1] = triangle[row - 1][col - 1] + dp[row - 2][col - 2];
				else
					dp[row - 1][col - 1] = triangle[row - 1][col - 1] + min(dp[row - 2][col - 1] , dp[row - 2][col - 2]);
			}
		}
	}
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		int row = triangle.size();
		if (row == 1) //if just one element
			return triangle[0][0];
		vector<vector<int>> dp(row, vector<int>(row, -1));

		solve(row, triangle, dp);

		//finding minimum in the last row
		int ans = INT_MAX;
		for (int col = 1; col <= row; col++) {
			ans = min(ans, dp[row - 1][col - 1]);
		}

		return ans;
	}
};