/*
Author: Harshit Tiwari
Date: 01-07-2022
https://leetcode.com/problems/wiggle-subsequence/
*/


class Solution {
public:
	int wiggleMaxLength(vector<int>& nums) {
		vector<int> vec;
		vec.push_back(nums[0]);
		int p = 0; int n = 0;
		for (int i = 1; i < nums.size(); i++) {
			if (nums[i] < nums[i - 1]) {
				if (n == 0) {
					vec.push_back(nums[i]);
					n = 1; p = 0;
				}
			}
			else if (nums[i] > nums[i - 1]) {
				if (p == 0) {
					vec.push_back(nums[i]);
					p = 1; n = 0;
				}
			}
		}
		return vec.size();
	}
};
