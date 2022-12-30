/*
Author: Harshit Tiwari
Date: 29-12-2022
https://leetcode.com/problems/maximum-population-year/
*/

// T.C: O(nlogn) (due to sorting) where n = 2*logs.size(). A better O(n) solution is in MaxPopulationYear_Soln1

class Solution {
public:
	int maximumPopulation(vector<vector<int>>& logs) {
		vector<int> years;
		unordered_map<int, int> birth;
		unordered_map<int, int> death;

		for (auto i : logs) {
			years.push_back(i[0]);
			years.push_back(i[1]);
			birth[i[0]]++;
			death[i[1]]++;
		}
		sort(years.begin(), years.end());
		int maxPopulation = 0; int ans; int currPop = 0;
		for (int i = 0; i < years.size(); i++) {
			if (birth.find(years[i]) != birth.end() && birth[years[i]] != 0) {
				birth[years[i]]--;
				currPop++;
			}
			if (death.find(years[i]) != death.end() && death[years[i]] != 0) {
				death[years[i]]--;
				currPop--;
			}
			if (currPop > maxPopulation) {
				maxPopulation = currPop;
				ans = years[i];
			}
		}
		return ans;
	}
};