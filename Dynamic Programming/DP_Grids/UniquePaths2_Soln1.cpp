/*
Author: Harshit Tiwari
Date: 04-07-2022
https://leetcode.com/problems/unique-paths-ii/
*/

//Recursion + Memoization (Top Down) DP approach.

class Solution {
private:
	int solve(int m, int n, vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp) {
		//if obstacle found return 0
		if (obstacleGrid[m - 1][n - 1] == 1)
			return dp[m - 1][n - 1] = 0;
		//Base conditions:
		if (m == 1 && n == 1) //starting position
			return dp[0][0] = 1;
		if (m == 1)      //1st row
			return dp[m - 1][n - 1] = solve(m, n - 1, obstacleGrid, dp);
		if (n == 1)      //1st column
			return dp[m - 1][n - 1] = solve(m - 1, n, obstacleGrid, dp);

		if (dp[m - 1][n - 1] != -1)
			return dp[m - 1][n - 1];

		return dp[m - 1][n - 1] = solve(m - 1, n, obstacleGrid, dp) + solve(m, n - 1, obstacleGrid, dp);
	}
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		int m = obstacleGrid.size();
		int n = obstacleGrid[0].size();
		vector<vector<int>> dp(m, vector<int>(n, -1));
		if (obstacleGrid[0][0] == 1) //if obstacle found at starting position itself
			return 0;
		return solve(m, n, obstacleGrid, dp);
	}
};