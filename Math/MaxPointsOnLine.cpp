/*
Author: Harshit Tiwari
Date: 08-06-2022
https://leetcode.com/problems/max-points-on-a-line/
*/

class Solution {
public:
	int maxPoints(vector<vector<int>>& points) {
		int ans = INT_MIN;
		for (int i = 0; i < points.size(); i++) {
			unordered_map<double, int> mp;
			for (int j = i + 1; j < points.size(); j++) {
				if (points[j][0] - points[i][0] == 0) {
					if (mp.find(INT_MAX) == mp.end())
						mp[INT_MAX] += 2;
					else
						mp[INT_MAX]++;
					continue;
				}
				double slope = (1.0 * (points[j][1] - points[i][1]) / (points[j][0] - points[i][0]));
				if (mp.find(slope) == mp.end())
					mp[slope] += 2;
				else
					mp[slope]++;
			}
			for (auto k : mp) {
				ans = max(ans, k.second);
			}
		}
		return ans == INT_MIN ? 1 : ans;
	}
};