/*
Author: Harshit Tiwari
Date: 20-11-2022
https://leetcode.com/problems/minimum-fuel-cost-to-report-to-the-capital/
*/

class Solution {
public:
	long long fuel = 0;
	int DFS(int parent, int root, unordered_map<int, vector<int>>& mp, int& seats) {
		long long cities = 1;
		for (auto j : mp[root]) {
			if (j != parent) {
				cities += DFS(root, j, mp, seats);
			}
		}
		if (root != 0) {
			fuel += (long long)ceil(float(cities) / (float(seats)));
		}
		return cities;
	}

	long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
		unordered_map<int, vector<int>> mp;
		for (int i = 0; i < roads.size(); i++) {
			if (mp.find(roads[i][0]) == mp.end()) {
				mp.insert({roads[i][0], vector<int>()});
			}
			if (mp.find(roads[i][1]) == mp.end()) {
				mp.insert({roads[i][1], vector<int>()});
			}
			mp[roads[i][0]].push_back(roads[i][1]);
			mp[roads[i][1]].push_back(roads[i][0]);
		}

		DFS(-1, 0, mp, seats);
		return fuel;
	}
};