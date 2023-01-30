/*
Author: Harshit Tiwari
Date: 29-01-2023
https://leetcode.com/problems/palindrome-partitioning-ii/
*/

class Solution {
public:
	bool isPalindrome(string& s) {
		int i = 0; int j = s.size() - 1;
		while (i < j) {
			if (s[i] != s[j])
				return false;
			i++; j--;
		}
		return true;
	}
	int solve(string s, int i, vector<int>& dp) {
		if (i == s.size())
			return 0;

		if (dp[i] != -1)
			return dp[i];

		string temp = ""; int ans = INT_MAX;
		for (int j = i; j < s.size(); j++) {
			temp.push_back(s[j]);
			if (isPalindrome(temp)) {
				ans = min(ans, 1 + solve(s, j + 1, dp));
			}
		}
		return dp[i] = ans;
	}
	int minCut(string s) {
		vector<int> dp(s.size(), -1);
		return solve(s, 0, dp) - 1;
	}
};