/*
Author: Harshit Tiwari
Date: 01-04-2022
https://practice.geeksforgeeks.org/problems/ncr1019/1#
*/

// This will give TLE for large inputs on gfg. Tabulation DP works here.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int factorial(int n, vector<long long int> &fac);
int nCr(int n, int r);

int main(){
    int n; cin>>n;
    int r; cin>>r;

    cout<<nCr(n,r)<<endl;
}

int nCr(int n, int r){
    int M = 1000000007;  //ans is to be given in modulo 1e9+7
    vector<vector<int>> dp(n+1, vector<int> (r+1,-1)); 
    if(r>n)
        return dp[n][r]=0;
    if(r==0 || r==n)
        return dp[n][r]=1;
    if(dp[n][r]!=-1)
        return dp[n][r];
    dp[n][r]= nCr(n-1,r-1)+ nCr(n-1,r);
    return (dp[n][r])%M;
}