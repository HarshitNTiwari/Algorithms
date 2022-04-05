/*
Author: Harshit Tiwari
Date: 04-04-2022
Problem: https://www.codingninjas.com/codestudio/problems/count-ways-to-reach-nth-stairs_798650
*/

//Recursive and Memoized (Top-down approach) solution

#include <iostream>
#include <vector>
using namespace std;

int solve(long long nStairs,vector<long long>& dp);
int countDistinctWayToClimbStair(long long nStairs);

long long M= 1e9+7;

int main(){
    int n; cin>>n;
    cout<<countDistinctWayToClimbStair(n)<<endl;
}

int solve(long long nStairs,vector<long long>& dp){
    // Base conditions
    if(nStairs==0)
        return dp[0]=1;
    if(nStairs==1)
        return dp[1]=1;
    // Checking if the value has already been computed and exists in dp array
    if(dp[nStairs]!=-1)
        return ((dp[nStairs]) % M);
    // Recursive code:
    return dp[nStairs]=(((solve(nStairs-1,dp) % M)+(solve(nStairs-2,dp) % M))) % M;
}

int countDistinctWayToClimbStair(long long nStairs){
    vector<long long> dp(nStairs+1,-1);
    return (solve(nStairs,dp) % M);
}