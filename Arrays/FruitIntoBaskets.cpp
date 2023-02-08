/*
Author: Harshit Tiwari
Date: 08-02-2023
https://leetcode.com/problems/fruit-into-baskets/
*/

class Solution {
public:
	int totalFruit(vector<int>& fruits) {
		unordered_map<int, int> umap;
		int i = 0; int j = 0; int ans = INT_MIN;
		while (j < fruits.size()) {
			umap[fruits[j]]++;

			while (umap.size() > 2) {
				if (--umap[fruits[i]] == 0)
					umap.erase(fruits[i]);
				i++;
			}

			if (umap.size() <= 2)
				ans = max(ans, j - i + 1);
			j++;
		}
		return ans;
	}
};