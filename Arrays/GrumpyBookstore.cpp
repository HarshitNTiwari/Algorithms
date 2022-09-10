/*
Author: Harshit Tiwari
Date: 17-08-2022
https://leetcode.com/problems/grumpy-bookstore-owner/
*/


class Solution {
public:
	int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
		int ans = 0;
		for (int i = 0; i < customers.size(); i++) {
			if (grumpy[i] == 0) {
				ans += customers[i];
			}
		}
		for (int i = 0; i < customers.size(); i++) {
			customers[i] *= grumpy[i];
		}
		int start = 0; int end = 0; int sum = 0; int count = 0;
		while (end < customers.size()) {
			sum += customers[end];
			while (end - start + 1 > minutes) {
				sum -= customers[start];
				start++;
			}
			count = max(count, sum);
			end++;
		}
		return ans + count;
	}
};