/*
Author: Harshit Tiwari
Date: 15-12-2022
https://leetcode.com/problems/kth-largest-element-in-a-stream
*/

class KthLargest {
public:
	int k_new = 0;
	priority_queue<int, vector<int>, greater<int>> pq;
	KthLargest(int k, vector<int>& nums) {
		k_new = k;
		for (auto i : nums) {
			pq.push(i);
		}
		while (pq.size() > k_new) {
			pq.pop();
		}
	}

	int add(int val) {
		pq.push(val);
		if (pq.size() > k_new)
			pq.pop();

		return pq.top();
	}
};