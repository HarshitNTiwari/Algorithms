/*
Author: Harshit Tiwari
Date: 07-01-2023
https://leetcode.com/problems/maximize-the-topmost-element-after-k-moves/
*/

class Solution {
public:
	int maximumTop(vector<int>& nums, int k) {
		if (nums.size() == 1)
			return k % 2 != 0 ? -1 : nums[0];
		if (nums.size() < k)
			return *max_element(nums.begin(), nums.end());
		int maxi = INT_MIN;
		for (int i = 0; i < k - 1; i++) {
			maxi = max(nums[i], maxi);
		}
		if (nums.size() > k)
			if (nums[k] > maxi)
				return nums[k];
		return maxi;
	}
};