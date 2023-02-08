/*
Author: Harshit Tiwari
Date: 06-02-2023
https://leetcode.com/problems/sliding-window-maximum/
*/

class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		vector<int> ans;
		priority_queue<pair<int, int>> pq;
		int maxi = INT_MIN;
		for (int i = 0; i < k; i++)
			pq.push({nums[i], i});
		ans.push_back(pq.top().first);

		int i = 1; int j = k;
		while (j < nums.size()) {
			while (!pq.empty() && pq.top().second < i) {
				pq.pop();
			}
			pq.push({nums[j], j});
			ans.push_back(pq.top().first);
			i++; j++;
		}
		return ans;
	}
};