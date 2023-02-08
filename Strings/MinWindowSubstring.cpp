/*
Author: Harshit Tiwari
Date: 06-02-2023
https://leetcode.com/problems/minimum-window-substring/
*/


class Solution {
public:
	string minWindow(string s, string t) {
		unordered_map<char, int> umap;
		for (char c : t)
			umap[c]++;

		int count = t.size();
		int i = 0; int j = 0;
		pair<int, int> p = {1, INT_MAX };

		while (j < s.size()) {
			if (umap[s[j]] > 0)
				count--;
			umap[s[j]]--;
			while (!count) {
				if (j - i + 1 < p.second - p.first + 1)
					p = {i, j};
				umap[s[i]]++;
				if (umap[s[i]] > 0)
					count++;
				i++;
			}
			j++;
		}
		cout << i << " " << j << endl;
		return p.second == INT_MAX ? "" : s.substr(p.first, p.second - p.first + 1);
	}
};