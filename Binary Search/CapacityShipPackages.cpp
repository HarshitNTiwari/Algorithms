/*
Author: Harshit Tiwari
Date: 05-01-2023
https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
*/

class Solution {
public:
	int shipWithinDays(vector<int>& weights, int days) {
		int hi = 0;
		for (int i = 0; i < weights.size(); i++)
			hi += weights[i];
		int lo = INT_MIN;
		for (int i = 0; i < weights.size(); i++)
			lo = max(lo, weights[i]);

		int c = 0;
		while (lo <= hi) {
			c = (lo + hi) / 2;
			int d = 0; int sum = 0;
			int i = INT_MIN; int j = 0;
			while (j < weights.size()) {
				sum += weights[j];
				if (sum == c) {
					d++; sum = 0; i = j;
				}
				else if (sum > c) {
					d++; sum = weights[j];
				}
				j++;
			}
			if (i != weights.size() - 1)
				d++;
			if (d > days)
				lo = c + 1;
			else
				hi = c - 1;
		}
		return lo;
	}
};