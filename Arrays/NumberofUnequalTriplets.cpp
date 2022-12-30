/*
Author: Harshit Tiwari
Date: 20-11-2022
https://leetcode.com/problems/number-of-unequal-triplets-in-array/
*/

class Solution {
public:
	int unequalTriplets(vector<int>& nums) {
		int count = 0;
		for (int i = 0 ; i < nums.size(); i++) {
			int f = nums[i];
			for (int j = i + 1; j < nums.size(); j++) {
				int m = nums[j];
				for (int k = j + 1; k < nums.size(); k++) {
					int l = nums[k];
					if (f != m && f != l && m != l)
						count++;
				}
			}
		}
		return count;
	}
};