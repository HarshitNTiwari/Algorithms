/*
Author: Harshit Tiwari
Date: 09-06-2022
https://codeforces.com/problemset/problem/230/A
*/

// The greedy approach is that among the dargons whose strength is less than ours, we will
// first fight with the one for which we get the max bonus.

#include<bits/stdc++.h>
using namespace std;

void solve();
bool sortbysecdesc(const pair<int, int> &a, const pair<int, int> &b) ;

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
	int s; int n;
	cin >> s >> n;
	vector<pair<int, int>> vect; //vector of pairs to store the 'dragon's strength- bonus' pair.
	int st, b;
	for (int i = 0; i < n; i++) {
		cin >> st >> b;
		vect.push_back(make_pair(st, b));
	}
	int count = 0;  //to count the number of dragons killed
	sort(vect.begin(), vect.end(), sortbysecdesc); //sorting the vector in descending order of bonus
	for (int i = 0; i < vect.size();) {
		if (vect[i].first < s) {
			count++;
			s += vect[i].second;
			vect.erase(vect.begin() + i);
			i = 0;
		}
		else
			i++;
	}
	if (count == n)
		cout << "YES" << " ";
	else
		cout << "NO";
	return;
}

bool sortbysecdesc(const pair<int, int> &a, const pair<int, int> &b) {
	return a.second > b.second;
}

