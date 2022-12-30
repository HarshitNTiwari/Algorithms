/*
Author: Harshit Tiwari
Date: 26-12-2022
https://leetcode.com/problems/longest-consecutive-sequence/
*/

class Solution {
public:
	int longestConsecutive(vector<int>& nums) {
		unordered_set<int> mp;
		for (int i = 0; i < nums.size(); i++) {
			mp.insert(nums[i]);
		}
		int maxi = 0;
		for (int i = 0; i < nums.size(); i++) {
			// If nums[i]-1 is not found in the array, then nums[i] is the beginning of some sequence
			if (mp.find(nums[i] - 1) == mp.end()) {
				int currNum = nums[i];
				int currLen = 1;

				// keep checking if consecutive nos. after nums[i] are present in the array
				while (mp.find(currNum + 1) != mp.end()) {
					currLen++;
					currNum++;
				}

				maxi = max(maxi, currLen);
			}
		}
		return maxi;
	}
};