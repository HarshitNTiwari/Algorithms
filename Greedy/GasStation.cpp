/*
Author: Harshit Tiwari
Date: 07-01-2023
https://leetcode.com/problems/gas-station/
*/

class Solution {
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		int balanceFuel = 0; int currFuel = 0; int ans = 0;
		for (int i = 0; i < gas.size(); i++) {
			balanceFuel += gas[i] - cost[i];
			currFuel += gas[i] - cost[i];
			if (currFuel < 0) {
				ans = i + 1;
				currFuel = 0;
			}
		}
		return balanceFuel < 0 ? -1 : ans;
	}
};