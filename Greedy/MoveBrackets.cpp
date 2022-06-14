/*
Author: Harshit Tiwari
Date: 09-06-2022
https://codeforces.com/problemset/problem/1374/C
*/

// We calculate the difference of no. of opening '(' and closing ')' before a particular index.
// If it comes out to be negative, that means the current index is ')'. So we remove it from here
// and move to the end.

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
	cin >> t;
	while (t--) {
		solve();
		cout << "\n";
	}
	return 0;
}

void solve() {
	int n; cin >> n;
	string s; cin >> s;
	int count = 0;   //to count the no. of operations
	int o = 0, c = 0;
	for (int i = 0; i < s.size();) {
		if (s[i] == '(')
			o++;
		else if (s[i] == ')')
			c++;
		int d = o - c;
		if (d < 0) {    //that means that the current character of s is ')' (since c>o)
			s.push_back(s[i]);  //move the ')' to the end of s
			s.erase(s.begin() + i);  //removing ')' from this index
			count++;
			i = 0;
			o = c = 0;
		}
		else
			i++;
	}
	cout << count << " ";
	return;
}

