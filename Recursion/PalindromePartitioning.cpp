/*
Author: Harshit Tiwari
Date: 29-01-2023
https://leetcode.com/problems/palindrome-partitioning/
*/

class Solution {
public:
	bool isPalindrome(string s) {
		int i = 0; int j = s.size() - 1;
		while (i < j) {
			if (s[i] != s[j])
				return false;
			i++; j--;
		}
		return true;
	}
	void solve(vector<vector<string>>& ans, vector<string>& temp, string s, int i) {
		if (i == s.size()) {
			ans.push_back(temp);
			return;
		}
		string tempStr = "";
		for (int j = i; j < s.size(); j++) {
			tempStr.push_back(s[j]);
			if (isPalindrome(tempStr)) {
				temp.push_back(tempStr);
				solve(ans, temp, s, j + 1);
				temp.pop_back();
			}
		}
		return;
	}
	vector<vector<string>> partition(string s) {
		vector<vector<string>> ans;
		vector<string> temp;
		solve(ans, temp, s, 0);
		return ans;
	}
};