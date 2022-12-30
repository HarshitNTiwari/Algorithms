/*
Author: Harshit Tiwari
Date: 27-12-2022
https://leetcode.com/problems/number-of-zero-filled-subarrays/
*/

class Solution {
public:
	long long zeroFilledSubarray(vector<int>& nums) {
		int j = 0;
		long long ans = 0; long long count = 0;
		while (j < nums.size()) {
			if (nums[j] == 0) {
				ans += count + 1;
				count++;
			}
			else {
				count = 0;
			}
			j++;
		}
		return ans;
	}
};