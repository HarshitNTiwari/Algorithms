/*
Author: Harshit Tiwari
Date: 05-01-2023
https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/
*/

class Solution {
public:
	int smallestDivisor(vector<int>& nums, int threshold) {
		int lo = 1; int hi = *max_element(nums.begin(), nums.end());
		int d = 0;
		while (lo <= hi) {
			d = (lo + hi) / 2;
			int sum = 0;
			for (int i = 0; i < nums.size(); i++)
				sum += ceil(1.0 * nums[i] / d);

			if (sum > threshold)
				lo = d + 1;
			else
				hi = d - 1;
		}
		return lo;
	}
};