/*
Author: Harshit Tiwari
Date: 05-01-2023
https://leetcode.com/problems/split-array-largest-sum/
*/

class Solution {
public:
	int splitArray(vector<int>& nums, int k) {
		if (k == nums.size())
			return *max_element(nums.begin(), nums.end());
		int lo = *max_element(nums.begin(), nums.end());
		int hi = 0;
		for (int i = 0; i < nums.size(); i++)
			hi += nums[i];
		int sum = 0;
		while (lo <= hi) {
			sum = (lo + hi) / 2;
			int count = 0; int currSum = 0;
			int i = 0; int j = 0;
			while (j < nums.size()) {
				currSum += nums[j];
				if (currSum == sum) {
					count++; currSum = 0; i = j;
				}
				else if (currSum > sum) {
					count++; currSum = nums[j];
				}
				j++;
			}
			if (i != nums.size() - 1)
				count++;
			if (count > k)
				lo = sum + 1;
			else
				hi = sum - 1;
		}
		return lo;
	}
};