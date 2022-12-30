/*
Author: Harshit Tiwari
Date: 27-12-2022
https://leetcode.com/problems/arithmetic-slices/
*/

class Solution {
public:
	int numberOfArithmeticSlices(vector<int>& nums) {
		if (nums.size() < 3)
			return 0;
		int i = 0; int j = 1;
		int ans = 0; int prevDiff = nums[j] - nums[j - 1];
		while (j < nums.size()) {
			if (j - i + 1 >= 3) {
				if (nums[j] - nums[j - 1] == prevDiff) {
					ans += (j - i + 1) - 3 + 1;
				}
				else {
					i = j - 1;
					prevDiff = nums[j] - nums[j - 1];
					continue;
				}
			}
			j++;
		}
		return ans;
	}
};