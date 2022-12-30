/*
Author: Harshit Tiwari
Date: 28-12-2022
https://leetcode.com/problems/arithmetic-subarrays/
*/

class Solution {
public:
	vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
		vector<bool> ans;
		for (int i = 0; i < l.size(); i++) {
			vector<int> subArr;
			subArr.assign(nums.begin() + l[i], nums.begin() + r[i] + 1);
			sort(subArr.begin(), subArr.end());

			int j = 2; int flag = 0;
			int diff = subArr[1] - subArr[0];
			while (j < subArr.size()) {
				if (subArr[j] - subArr[j - 1] != diff) {
					flag = 1;
					ans.push_back(false);
					break;
				}
				j++;
			}
			if (!flag) {
				ans.push_back(true);
			}
		}
		return ans;
	}
};