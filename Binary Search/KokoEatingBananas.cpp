/*
Author: Harshit Tiwari
Date: 03-01-2023
https://leetcode.com/problems/koko-eating-bananas/
*/

class Solution {
public:
	int minEatingSpeed(vector<int>& piles, int h) {
		int hi = INT_MIN;
		for (int i = 0; i < piles.size(); i++)
			hi = max(hi, piles[i]);

		int lo = 1; int k = 0;
		while (lo <= hi) {
			k = (lo + hi) / 2;
			long time = 0;
			//calculating the total time taken to eat up all the piles acc to the curent k
			for (int i = 0; i < piles.size(); i++)
				time += ceil(1.0 * piles[i] / k);
			if (time > h)
				lo = k + 1;
			else
				hi = k - 1;
		}
		return lo;
	}
};