/*
Author: Harshit Tiwari
Date: 30-06-2022
https://leetcode.com/problems/shortest-unsorted-continuous-subarray/
*/


class Solution {
public:
	int findUnsortedSubarray(vector<int>& nums) {
		int ans = 0; int count = 1;
		vector<int> st;
		st.push_back(nums[0]);

		int start = INT_MAX; int end = 0;
		for (int i = 1; i < nums.size(); i++) {
			if (nums[i] >= st[st.size() - 1]) {
				st.push_back(nums[i]);
			}
			else if (nums[i] < st[st.size() - 1]) {
				end = i;
				int n = st.size() - 1;
				while (n >= 0 && nums[i] < st[n]) {
					start = min(start, n);
					n--;
				}
				ans = end - start + 1;
			}
		}
		return ans;
	}
};