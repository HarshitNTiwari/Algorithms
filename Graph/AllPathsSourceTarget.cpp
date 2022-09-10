/*
Author: Harshit Tiwari
Date: 17-08-2022
https://leetcode.com/problems/all-paths-from-source-to-target/
*/

// Solved using backtracking

class Solution {
	void DFS(vector<vector<int>>& graph, int root, vector<int>& temp, vector<vector<int>>& ans) {
		if (root == graph.size() - 1) {
			ans.push_back(temp);
			return;
		}
		for (int i = 0; i < graph[root].size(); i++) {
			temp.push_back(graph[root][i]);
			DFS(graph, graph[root][i], temp, ans);
			temp.pop_back();
		}
		return;
	}
public:
	vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
		int n = graph.size();
		vector<vector<int>> ans;
		vector<int> temp;
		temp.push_back(0);
		DFS(graph, 0, temp, ans);
		return ans;
	}
};