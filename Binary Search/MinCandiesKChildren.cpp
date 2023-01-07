/*
Author: Harshit Tiwari
Date: 04-01-2023
https://leetcode.com/problems/maximum-candies-allocated-to-k-children/
*/

class Solution {
public:
	int maximumCandies(vector<int>& candies, long long k) {
		int hi = INT_MIN;
		for (int i = 0; i < candies.size(); i++)
			hi = max(hi, candies[i]);

		int lo = 1; int c = 0; int ans = INT_MIN;
		while (lo <= hi) {
			c = (lo + hi) / 2;
			long long children = 0;
			for (int i = 0; i < candies.size(); i++)
				children += candies[i] / c;
			if (children < k)
				hi = c - 1;
			else {
				lo = c + 1;
				ans = max(ans, c);
			}
		}
		return ans == INT_MIN ? 0 : ans;
	}
};