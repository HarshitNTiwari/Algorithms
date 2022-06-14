/*
Author: Harshit Tiwari
Date: 12-04-2022
Problem: https://codeforces.com/problemset/problem/1182/A
*/

// Although this question is tagged as 'dp' on codeforces, dp isn't really required. Simple recursion would work. 

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solve(int n, vector<int> &dp);

int main(){
    int n; cin>>n;
    vector<int> dp(n, -1);

    cout<< solve(n,dp)<<endl;

    return 0;
}

int solve(int n, vector<int> &dp){
    if(n%2!=0)
        return dp[n-1]=0;
    if(n==2)
        return dp[1]=2;
    if(dp[n-1]!=-1)
        return dp[n-1];
    
    return dp[n-1]= solve(n-2,dp)*2;
}