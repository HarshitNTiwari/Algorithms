/*
Author: Harshit Tiwari
Date: 14-09-2022
https://leetcode.com/problems/is-graph-bipartite/
*/

class Solution {
	bool bfs(vector<vector<int>>& graph, int s, vector<int>& vec) {
		queue<int> q;
		q.push(s);
		vec[s] = 0;
		while (!q.empty()) {
			int u = q.front();
			q.pop();
			int newState = 0;
			if (vec[u] == 0)
				newState = 1;
			for (int i : graph[u]) {
				if (vec[i] == -1) {
					vec[i] = newState;
					q.push(i);
					continue;
				}
				if (vec[i] == vec[u])
					return false;
			}
		}
		return true;
	}
public:
	bool isBipartite(vector<vector<int>>& graph) {
		vector<int> vec(graph.size(), -1);
		for (int i = 0; i < graph.size(); i++) {
			if (vec[i] == -1) {
				if (!bfs(graph, i, vec))
					return false;
			}
		}
		return true;
	}
};