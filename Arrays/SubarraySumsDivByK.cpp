/*
Author: Harshit Tiwari
Date: 21-01-2023
https://leetcode.com/problems/subarray-sums-divisible-by-k/
*/

class Solution {
public:
	int subarraysDivByK(vector<int>& nums, int k) {
		unordered_map<int, int> umap;
		umap[0]++;
		int pSum = 0; int ans = 0;
		for (int i = 0; i < nums.size(); i++) {
			pSum += nums[i];
			int rem = ((pSum % k) + k) % k;
			if (umap.find(rem) != umap.end())
				ans += umap[rem];
			umap[rem]++;
		}
		return ans;
	}
};