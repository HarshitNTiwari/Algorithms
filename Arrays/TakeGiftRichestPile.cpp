/*
Author: Harshit Tiwari
Date: 05-02-2023
https://leetcode.com/problems/take-gifts-from-the-richest-pile/
*/

class Solution {
public:
	long long pickGifts(vector<int>& gifts, int k) {
		priority_queue<long long> pq;
		for (int i : gifts)
			pq.push(i);
		while (k && !pq.empty()) {
			int t = pq.top();
			long long  nt = floor(sqrt(t));
			pq.pop();
			pq.push(nt);
			k--;
		}
		long long sum = 0;
		while (!pq.empty()) {
			sum += pq.top();
			pq.pop();
		}
		return sum;
	}
};