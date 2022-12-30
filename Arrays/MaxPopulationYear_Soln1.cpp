/*
Author: Harshit Tiwari
Date: 29-12-2022
https://leetcode.com/problems/maximum-population-year/
*/

// T.C.: O(n). An alternative solution is in MaxPopulationYear_Soln2.cpp

class Solution {
public:
	int maximumPopulation(vector<vector<int>>& logs) {
		vector<int> years(101, 0);
		for (auto i : logs) {
			years[i[0] - 1950]++;
			years[i[1] - 1950]--;
		}
		int maxPopulation = years[0]; int ans = 1950;
		for (int i = 1; i < 100; i++) {
			years[i] += years[i - 1];
			if (years[i] > maxPopulation) {
				maxPopulation = years[i];
				ans = i + 1950;
			}
		}
		return ans;
	}
};