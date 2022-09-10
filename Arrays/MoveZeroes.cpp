/*
Author: Harshit Tiwari
Date: 10-09-2022
https://leetcode.com/problems/move-zeroes/
*/

class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		int i = 0; int j = 0;
		while (i < nums.size()) {
			if (nums[j] == 0) {
				nums.push_back(0);
				nums.erase(nums.begin() + j);
			}
			else {
				j++;
			}
			i++;
		}
	}
};