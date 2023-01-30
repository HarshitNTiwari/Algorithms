/*
Author: Harshit Tiwari
Date: 29-01-2023
https://leetcode.com/problems/letter-case-permutation/
*/

class Solution {
public:
	void solve(string s, int i, vector<string>& ans) {
		if (i == s.size()) {
			ans.push_back(s);
			return;
		}
		if (('A' <= s[i] && s[i] <= 'Z') || ('a' <= s[i] && s[i] <= 'z')) {
			if (i == 0) {
				solve((char)tolower(s[i]) + s.substr(i + 1), i + 1, ans);
				solve((char)toupper(s[i]) + s.substr(i + 1), i + 1, ans);
			}
			else if (i == s.size() - 1) {
				solve(s.substr(0, i) + (char)tolower(s[i]), i + 1, ans);
				solve(s.substr(0, i) + (char)toupper(s[i]), i + 1, ans);
			}
			else {
				solve(s.substr(0, i) + (char)tolower(s[i]) + s.substr(i + 1), i + 1, ans);
				solve(s.substr(0, i) + (char)toupper(s[i]) + s.substr(i + 1), i + 1, ans);
			}

		}
		else {
			solve(s, i + 1, ans);
		}
		return;
	}
	vector<string> letterCasePermutation(string s) {
		vector<string> ans;
		solve(s, 0, ans);
		return ans;
	}
};