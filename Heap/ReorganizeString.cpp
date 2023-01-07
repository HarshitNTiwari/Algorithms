/*
Author: Harshit Tiwari
Date: 07-01-2023
https://leetcode.com/problems/reorganize-string/
*/

class Solution {
public:
	string reorganizeString(string s) {
		unordered_map<char, int> freq;
		priority_queue<pair<int, char>> pq;

		for (auto i : s)
			freq[i]++;
		for (auto i : freq)
			pq.push({i.second, i.first});

		pair<int, char> temp = make_pair(0, '0');

		string ans = "";
		while (!pq.empty()) {
			pair<int, char> curr = pq.top();
			pq.pop();

			ans.push_back(curr.second);
			curr.first--;

			if (temp.first != 0) {
				pq.push(temp);
				temp = make_pair(0, '0');
			}

			if (curr.first)
				temp = make_pair(curr.first, curr.second);
		}
		if (pq.empty() && temp.first != 0)
			return "";
		return ans;
	}
};