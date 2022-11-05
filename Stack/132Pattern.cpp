/*
Author: Harshit Tiwari
Date: 04-11-2022
https://leetcode.com/problems/132-pattern/
*/

class Solution {
public:
	bool find132pattern(vector<int>& nums) {
		stack<int> st;
		int prev = INT_MIN;
		for (int i = nums.size() - 1; i >= 0; i--) {
			while (!st.empty() && nums[i] > st.top()) {
				if (prev > st.top())
					return true;
				prev = st.top();
				st.pop();
			}
			st.push(nums[i]);
		}
		return !st.empty() && prev > st.top();
	}
};