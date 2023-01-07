/*
Author: Harshit Tiwari
Date: 05-01-2023
https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/
*/

class Solution {
public:
	int minDays(vector<int>& bloomDay, int m, int k) {
		if ((long)m * k > (long)bloomDay.size())
			return -1;
		int hi = INT_MIN; int lo = INT_MAX;
		for (int i = 0; i < bloomDay.size(); i++) {
			hi = max(hi, bloomDay[i]);
			lo = min(lo, bloomDay[i]);
		}

		int days = 0;
		while (lo <= hi) {
			days = (lo + hi) / 2;
			int count = 0;
			int i = 0; int j = 0;
			while (j < bloomDay.size()) {
				if (bloomDay[j] <= days) {
					if (j - i + 1 == k) {
						count++;
						j++; i = j; continue;
					}
				}
				else {
					j++; i = j; continue;
				}
				j++;
			}
			if (count < m)
				lo = days + 1;
			else
				hi = days - 1;
		}
		return lo;
	}
};