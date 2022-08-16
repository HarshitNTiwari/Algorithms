/*
Author: Harshit Tiwari
Date: 06-07-2022
https://leetcode.com/problems/longest-common-subsequence/
*/

// Recursion + Memoization (Top Down) DP approach.

class Solution {
private:
	int solve(int len1, int len2, string& text1, string& text2, vector<vector<int>>& dp) {
		//Base Condition:
		if (len1 == 0 || len2 == 0)  //if length of one of the strings becomes 0
			return 0;

		if (dp[len1 - 1][len2 - 1] != -1)
			return dp[len1 - 1][len2 - 1];

		if (text1[len1 - 1] == text2[len2 - 1])  //if the characters are matched
			return dp[len1 - 1][len2 - 1] = 1 + solve(len1 - 1, len2 - 1, text1, text2, dp);
		else                                    //if characters not matched
			return dp[len1 - 1][len2 - 1] = max(solve(len1 - 1, len2, text1, text2, dp), solve(len1, len2 - 1, text1, text2, dp));
	}

public:
	int longestCommonSubsequence(string text1, string text2) {
		vector<vector<int>> dp(text1.size(), vector<int>(text2.size(), -1));
		return dp[text1.size() - 1][text2.size() - 1] = solve(text1.size(), text2.size(), text1, text2, dp);
	}
};