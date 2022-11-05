/*
Author: Harshit Tiwari
Date: 05-11-2022
https://leetcode.com/problems/find-the-most-competitive-subsequence/
*/

class Solution {
public:
	vector<int> mostCompetitive(vector<int>& nums, int k) {
		stack<int> st;
		vector<int> ans;
		for (int i = 0; i < nums.size(); i++) {
			while (!st.empty() && nums[i] < st.top() && (st.size() + nums.size() - i) > k) {
				st.pop();
			}
			st.push(nums[i]);
		}

		while (!st.empty()) {
			ans.push_back(st.top());
			st.pop();
		}

		reverse(ans.begin(), ans.end());
		vector<int> final;
		for (int i = 0; i < ans.size(); i++) {
			if (final.size() == k)
				break;
			final.push_back(ans[i]);
		}

		return final;
	}
};