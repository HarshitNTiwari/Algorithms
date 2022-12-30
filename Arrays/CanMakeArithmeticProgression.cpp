/*
Author: Harshit Tiwari
Date: 28-12-2022
https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/
*/

class Solution {
public:
	bool canMakeArithmeticProgression(vector<int>& arr) {
		sort(arr.begin(), arr.end());
		int j = 2; int diff = arr[1] - arr[0];
		while (j < arr.size()) {
			if (arr[j] - arr[j - 1] != diff)
				return false;
			j++;
		}
		return true;
	}
};