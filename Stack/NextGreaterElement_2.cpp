/*
Author: Harshit Tiwari
Date: 04-11-2022
https://leetcode.com/problems/next-greater-element-ii/
*/

// T.C. : O(n)

class Solution {
public:
	vector<int> nextGreaterElements(vector<int>& nums) {
		int n = nums.size();
		vector<int> ans(n, -1);
		stack<pair<int, int>> st;
		for (int i = 0; i < 2 * n; i++) {
			int k = i % n;
			while (!st.empty() && st.top().first < nums[k]) {
				ans[st.top().second] = nums[k];
				st.pop();
			}
			st.push({nums[k], k});
		}
		return ans;
	}
};