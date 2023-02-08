/*
Author: Harshit Tiwari
Date: 04-02-2023
https://leetcode.com/problems/replace-the-substring-for-balanced-string/
*/

class Solution {
public:
	int balancedString(string s) {
		int n = s.size();
		unordered_map<char, int> umap;
		for (auto i : s)
			umap[i]++;

		int i = 0; int j = 0; int ans = INT_MAX;
		while (j < s.size()) {
			umap[s[j]]--;
			while (i < n && umap['Q'] <= n / 4 && umap['W'] <= n / 4 && umap['E'] <= n / 4 && umap['R'] <= n / 4) {
				ans = min(ans, j - i + 1);
				umap[s[i]]++;
				i++;
			}
			j++;
		}
		return ans;
	}
};