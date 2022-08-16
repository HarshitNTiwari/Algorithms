/*
Author: Harshit Tiwari
Date: 06-07-2022
https://leetcode.com/problems/longest-common-subsequence/
*/

// Tabulation (bottom up) DP approach
// SC: O(text1.size()*text2.size())

class Solution {
private:
	int solve(int len1, int len2, string& text1, string& text2, vector<vector<int>>& dp) {
		//initialization of DP matrix:
		for (int col = 0; col <= len2; col++) { //length of text2 is 0
			dp[0][col] = 0;
		}
		for (int row = 0; row <= len1; row++) { //length of text1 is 0
			dp[row][0] = 0;
		}

		//filling up the dp matrix:
		for (int row = 1; row <= len1; row++) {
			for (int col = 1; col <= len2; col++) {
				if (text1[row - 1] == text2[col - 1])  //if the characters are matched
					dp[row][col] = 1 + dp[row - 1][col - 1];
				else                                   //if characters not matched
					dp[row][col] = max(dp[row - 1][col], dp[row][col - 1]);
			}
		}
		return dp[len1][len2];
	}
public:
	int longestCommonSubsequence(string text1, string text2) {
		vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, -1));
		return solve(text1.size(), text2.size(), text1, text2, dp);
	}
};