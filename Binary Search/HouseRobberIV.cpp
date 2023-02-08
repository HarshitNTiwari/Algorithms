/*
Author: Harshit Tiwari
Date: 05-02-2023
https://leetcode.com/problems/house-robber-iv/
*/


class Solution {
public:
	int minCapability(vector<int>& nums, int k) {
		int lo = *min_element(nums.begin(), nums.end());
		int hi = *max_element(nums.begin(), nums.end());

		while (lo < hi) {
			int maxCap = (lo + hi) / 2;
			int houses = 0;
			for (int i = 0; i < nums.size(); i++) {
				if (nums[i] <= maxCap) {
					houses++;
					i++;
				}
			}
			if (houses >= k)
				hi = maxCap;
			else
				lo = maxCap + 1;
		}
		return lo;
	}
};