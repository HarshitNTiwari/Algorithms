/*
Author: Harshit Tiwari
Date: 04-07-2022
https://leetcode.com/problems/unique-paths-ii/
*/

// Tabulation (bottom up) DP approach

class Solution {
private:
	int solve(int m, int n, vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp) {
		//initialization of dp matrix:
		dp[0][0] = 1;                //starting position
		for (int row = 1; row < m; row++) { //for 1st column
			if (obstacleGrid[row][0] == 1)
				dp[row][0] = 0;
			else
				dp[row][0] = dp[row - 1][0];
		}
		for (int col = 1; col < n; col++) { //for 1st row
			if (obstacleGrid[0][col] == 1)
				dp[0][col] = 0;
			else
				dp[0][col] = dp[0][col - 1];
		}

		//Filling up the DP matrix:
		for (int row = 1; row < m; row++) {
			for (int col = 1; col < n; col++) {
				if (obstacleGrid[row][col] == 1)
					dp[row][col] = 0;
				else
					dp[row][col] = dp[row - 1][col] + dp[row][col - 1];
			}
		}

		return dp[m - 1][n - 1];
	}
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		int m = obstacleGrid.size();
		int n = obstacleGrid[0].size();
		vector<vector<int>> dp(m, vector<int>(n, -1));
		if (obstacleGrid[0][0] == 1)  //if obstacle found at starting position itself
			return 0;
		return solve(m, n, obstacleGrid, dp);
	}
};