/*
Author: Harshit Tiwari
Date: 04-11-2022
https://leetcode.com/problems/next-greater-element-i/
*/

// T.C. : O(n)

class Solution {
public:
	vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
		vector<int> ans(nums1.size(), -1);
		unordered_map<int, int> index;
		for (int i = 0; i < nums1.size(); i++)
			index[nums1[i]] = i;
		stack<int> st;
		for (int j = 0; j < nums2.size(); j++) {
			while (!st.empty() && nums2[j] > st.top()) {
				if (index.find(st.top()) != index.end())
					ans[index[st.top()]] = nums2[j];
				st.pop();
			}
			st.push(nums2[j]);
		}
		return ans;
	}
};