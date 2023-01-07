/*
Author: Harshit Tiwari
Date: 04-01-2023
https://leetcode.com/problems/minimum-limit-of-balls-in-a-bag/
*/


class Solution {
public:
	int minimumSize(vector<int>& nums, int maxOperations) {
		int hi = *max_element(nums.begin(), nums.end());

		int lo = 1; int ans = 0;
		while (lo <= hi) {
			ans = (lo + hi) / 2;
			int op = 0;
			for (int i = 0; i < nums.size(); i++)
				op += ceil(1.0 * nums[i] / ans) - 1;
			if (op > maxOperations)
				lo = ans + 1;
			else
				hi = ans - 1;
		}
		return lo;
	}
};