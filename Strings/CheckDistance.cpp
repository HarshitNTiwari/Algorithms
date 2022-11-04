/*
Author: Harshit Tiwari
Date: 10-09-2022
https://leetcode.com/problems/check-distances-between-same-letters/
*/

class Solution {
public:
	bool checkDistances(string s, vector<int>& distance) {
		vector<int> dist(26, -1);
		for (int i = 0; i < s.size(); i++) {
			if (dist[s[i] - 'a'] == -1) {
				dist[s[i] - 'a'] = i;
			}
			else {
				dist[s[i] - 'a'] = i - dist[s[i] - 'a'] - 1;
			}
		}

		for (int i = 0; i < s.size(); i++) {
			if (dist[s[i] - 'a'] != distance[s[i] - 'a'])
				return false;
		}
		return true;
	}
};