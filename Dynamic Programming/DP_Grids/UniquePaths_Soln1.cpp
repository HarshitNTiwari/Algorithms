/*
Author: Harshit Tiwari
Date: 04-07-2022
https://leetcode.com/problems/unique-paths/
*/

// Recursion + Memoization (Top Down) DP approach. It may give TLE for very large inputs.

class Solution {
private:
    int solve(int m, int n, vector<vector<int>>& dp) {
        //Base condition:
        if (m == 1 || n == 1)
            return dp[m - 1][n - 1] = 1;

        if (dp[m - 1][n - 1] != -1)
            return dp[m - 1][n - 1];

        return dp[m - 1][n - 1] = solve(m - 1, n, dp) + solve(m, n - 1, dp);
    }

public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(m , n , dp);
    }
};