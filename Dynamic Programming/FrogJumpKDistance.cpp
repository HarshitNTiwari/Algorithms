/*
Author: Harshit Tiwari
Date: 04-04-2022
https://atcoder.jp/contests/dp/tasks/dp_b
*/

//Recursive and Memoized (Top-down approach) solution

#include <iostream>
#include <vector>
#include <algorithm>

#define INT_MAX 2147483647

using namespace std;

int frogJump(int n, int k,  vector<int> &heights, vector<int> &dp);

int main(){
    int N; int K;
    cin>>N>>K;
    vector<int> heights;
    for(int i=0;i<N;i++){
        int k; cin>>k;
        heights.push_back(k);
    }

    vector<int> dp(N,-1);

    cout<<frogJump(N,K,heights,dp)<<endl;
}

int frogJump(int n, int k,  vector<int> &heights, vector<int> &dp){
    if(n==1)
        return dp[0]=0;
    if(n==2)
        return dp[1]=abs(heights[1]-heights[0]);
    if(dp[n-1]!=-1)
        return dp[n-1];
    dp[n-1]=INT_MAX;
    int y= (n<=k)?n-1:k;
    for(int i=1;i<=y;i++){
        dp[n-1]=min(dp[n-1], frogJump(n-i,k,heights,dp)+abs(heights[n-1]-heights[n-1-i]));
    }
    return dp[n-1];
}
