/*
Author: Harshit Tiwari
Date: 09-06-2022
https://codeforces.com/problemset/problem/58/A
*/

// This solution is a greedy algorithm. At each letter of the input string 's' we compare it with
// the corresponding letter of "hello". If in such a way we can find all the letters of "hello"
// in the string 's' in the same order, then we return 'YES'.

// TC: O(n)

#include<bits/stdc++.h>
using namespace std;

void solve();

int main() {

	ios_base::sync_with_stdio(false); cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif


	int t = 1;
	// cin >> t;
	while (t--) {
		solve();
		cout << "\n";
	}
	return 0;
}

void solve() {
	string s; cin >> s;
	string w = "hello";
	int j = 0;
	int count = 0;
	for (int i = 0; (i < w.size() && j < s.size());) {
		if (w[i] == s[j]) {
			count++;
			i++;
			j++;
		}
		else
			j++;
	}
	if (count == w.size())
		cout << "YES" << " ";
	else
		cout << "NO" << " ";
	return;
}

