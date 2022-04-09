/*
Author: Harshit Tiwari
Date: 06-04-2022
https://leetcode.com/problems/unique-paths/
*/

// This is recursive and memoized solution. It may give TLE for very large inputs.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int uniquePaths(int m, int n);
int solve(int m, int n, vector<vector<int>>& dp);

int main(){
    int m; int n;
    cin>>m>>n;
    cout<< uniquePaths(m,n);
}

int solve(int m, int n, vector<vector<int>>& dp){
    if(m==1 || n==1)
        return 1;
    if(dp[m-1][n-1]!=-1)
        return dp[m-1][n-1];
	return dp[m-1][n-1] = solve(m-1,n,dp) + solve(m,n-1,dp);
}

int uniquePaths(int m, int n) {
	vector<vector<int>> dp(m, vector<int> (n, -1));
    return solve(m,n,dp);
}