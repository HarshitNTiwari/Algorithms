/*
Author: Harshit Tiwari
Date: 29-01-2023
https://leetcode.com/problems/generate-parentheses/
*/

class Solution {
public:
	void solve(string s, vector<string>& ans, int open, int close, int n) {
		if (s.size() == 2 * n) {
			ans.push_back(s);
			return;
		}
		if (open < n) {
			solve(s + "(", ans, open + 1, close, n);
		}
		if (close < open) {
			solve(s + ")", ans, open, close + 1, n);
		}
		return;
	}
	vector<string> generateParenthesis(int n) {
		vector<string> ans;
		solve("", ans, 0, 0, n);
		return ans;
	}
};