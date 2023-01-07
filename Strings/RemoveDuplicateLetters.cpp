/*
Author: Harshit Tiwari
Date: 07-01-2023
https://leetcode.com/problems/remove-duplicate-letters/
*/

class Solution {
public:
	string removeDuplicateLetters(string s) {
		unordered_map<char, int> freq;
		for (auto i : s)
			freq[i]++;
		unordered_map<char, bool> inStack;
		stack<char> st;

		st.push(s[0]);
		freq[s[0]]--;
		inStack[s[0]] = true;
		int j = 1;
		while (j < s.size()) {
			if (inStack[s[j]]) {
				freq[s[j]]--;
				j++;
				continue;
			}
			while (!st.empty() && s[j] < st.top() && freq[st.top()] > 0) {
				inStack[st.top()] = false;
				st.pop();
			}
			st.push(s[j]);
			freq[s[j]]--;
			inStack[s[j]] = true;
			j++;
		}
		string ans = "";
		while (!st.empty()) {
			ans.push_back(st.top());
			st.pop();
		}

		reverse(ans.begin(), ans.end());
		return ans;
	}
};