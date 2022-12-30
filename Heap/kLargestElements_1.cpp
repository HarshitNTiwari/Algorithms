/*
Author: Harshit Tiwari
Date: 18-11-2022
https://practice.geeksforgeeks.org/problems/k-largest-elements4206/1
*/

// TC: (n*logk + k*logK) = O((n+k)*logk)

class Solution {
public:
	vector<int> kLargest(int arr[], int n, int k) {
		priority_queue<int> pq;
		for (int i = 0; i < n; i++) {
			pq.emplace(arr[i]);
		}

		vector<int> ans;
		while (k) {
			ans.push_back(pq.top());
			pq.pop(); k--;
		}
		return ans;
	}

};