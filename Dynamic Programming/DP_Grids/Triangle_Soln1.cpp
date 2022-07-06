/*
Author: Harshit Tiwari
Date: 05-07-2022
https://leetcode.com/problems/triangle/
*/

//Recursion + Memoization (Top Down) DP approach.


class Solution {
private:
	int solve(int row, int col, vector<vector<int>>& triangle, vector<vector<int>>& dp) {
		//Base conditions:
		if (row == 1 && col == 1)  //topmost element
			return dp[0][0] = triangle[0][0];
		if (col == 1)
			return dp[row - 1][col - 1] = triangle[row - 1][col - 1] + solve(row - 1, col, triangle, dp);
		if (col == row)
			return dp[row - 1][col - 1] = triangle[row - 1][col - 1] + solve(row - 1, col - 1, triangle, dp);

		if (dp[row - 1][col - 1] != -1)
			return dp[row - 1][col - 1];

		return dp[row - 1][col - 1] = triangle[row - 1][col - 1] + min(solve(row - 1, col, triangle, dp) , solve(row - 1, col - 1, triangle, dp));
	}

public:
	int minimumTotal(vector<vector<int>>& triangle) {
		int row = triangle.size();
		if (row == 1) //if just one element
			return triangle[0][0];
		vector<vector<int>> dp(row, vector<int>(row, -1));

		//filling the last row of dp matrix
		for (int col = 1; col <= row; col++) {
			if (col == 1)
				dp[row - 1][col - 1] =  triangle[row - 1][col - 1] + solve(row - 1, col, triangle, dp);
			else if (col == row)
				dp[row - 1][col - 1] =  triangle[row - 1][col - 1] + solve(row - 1, col - 1, triangle, dp);
			else
				dp[row - 1][col - 1] = triangle[row - 1][col - 1] + min(solve(row - 1, col, triangle, dp) , solve(row - 1, col - 1, triangle, dp));
		}

		//finding minimum in the last row
		int ans = INT_MAX;
		for (int col = 1; col <= row; col++) {
			ans = min(ans, dp[row - 1][col - 1]);
		}

		return ans;
	}
};