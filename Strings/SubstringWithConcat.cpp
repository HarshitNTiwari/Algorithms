/*
Author: Harshit Tiwari
Date: 08-02-2023
https://leetcode.com/problems/substring-with-concatenation-of-all-words/
*/

class Solution {
public:
	bool solve(unordered_map<string, int> umap, int k, string s) {
		int i = 0;
		while (i < s.size() && !umap.empty()) {
			string curr = s.substr(i, k);
			if (umap[curr] > 0) {
				if (--umap[curr] == 0)
					umap.erase(curr);
			}
			else {
				return false;
			}
			i += k;
		}
		return true;
	}
	vector<int> findSubstring(string s, vector<string>& words) {
		int k = words[0].size(); int len = words.size();
		unordered_map<string, int> umap;
		for (string w : words)
			umap[w]++;

		vector<int> ans;
		int j = 0;
		while (j + (k * len) <= s.size()) {
			if (solve(umap, k, s.substr(j, k * len))) {
				ans.push_back(j);
			}
			j++;
		}
		return ans;
	}
};