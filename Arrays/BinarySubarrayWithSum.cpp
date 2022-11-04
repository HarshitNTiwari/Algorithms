/*
Author: Harshit Tiwari
Date: 12-09-2022
https://leetcode.com/problems/binary-subarrays-with-sum/
*/

class Solution {
	int solve(vector<int>& nums, int goal) {
		int i = 0; int j = 0; int count = 0; int sum = 0;
		while (j < nums.size()) {
			sum += nums[j];
			while (sum > goal && i <= j) {
				sum -= nums[i];
				i++;
			}
			count += j - i + 1;
			j++;
		}
		return count;
	}
public:
	int numSubarraysWithSum(vector<int>& nums, int goal) {
		return solve(nums, goal) - solve(nums, goal - 1);
	}
};