/*
Author: Harshit Tiwari
Date: 13-12-2022
https://leetcode.com/problems/kth-largest-element-in-an-array/
*/

// Solution using Max Priority Queue.

class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		priority_queue<int> pq;

		// creating a max heap
		for (int i = 0; i < nums.size(); i++) {
			pq.push(nums[i]);
		}

		k--;
		while (k) {  // removing top k-1 elements
			pq.pop();
			k--;
		}

		return pq.top();  // the element at the top is the answer
	}
};