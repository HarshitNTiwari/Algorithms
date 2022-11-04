/*
Author: Harshit Tiwari
Date: 14-09-2022
https://leetcode.com/problems/number-of-provinces/
*/

class Solution {
	void bfs(vector<vector<int>>& isConnected, int s, vector<int>& vec) {
		queue<int> q;
		q.push(s);
		vec[s] = 0;
		while (!q.empty()) {
			int u = q.front();
			q.pop();
			for (int j = 0; j < isConnected[u].size(); j++) {
				if (j != u && isConnected[u][j] == 1 && vec[j] == -1) {
					q.push(j);
					vec[j] = 0;
				}
			}
		}
	}
public:
	int findCircleNum(vector<vector<int>>& isConnected) {
		int count  = 0;
		vector<int> vec(isConnected.size(), -1);
		for (int i = 0; i < isConnected.size(); i++) {
			if (vec[i] == -1) {
				bfs(isConnected, i, vec);
				count++;
			}
		}
		return count;
	}
};