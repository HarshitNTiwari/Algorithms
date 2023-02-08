/*
Author: Harshit Tiwari
Date: 05-02-2023
https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/
*/


class Solution {
public:
	int shortestSubarray(vector<int>& nums, int k) {
		priority_queue <pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
		long long j = 0; long long ans = INT_MAX; long long sum = 0;
		while (j < nums.size()) {
			sum += (long long)nums[j];
			if (sum >= k)
				ans = min(ans, j + 1);
			while (!pq.empty() && sum - pq.top().first >= k) {
				ans = min(ans, j - pq.top().second);
				pq.pop();
			}
			pq.push({sum, j});
			j++;
		}
		return ans == INT_MAX ? -1 : ans;
	}
};