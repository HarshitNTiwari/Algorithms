/*
Author: Harshit Tiwari
Date: 04-04-2022
https://www.codingninjas.com/codestudio/problems/frog-jump_3621012
*/

//Recursive and Memoized (Top-down approach) solution

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int frogJump(int n, vector<int> &heights, vector<int> &dp);

int main(){
    int N;  cin>>N;
    vector<int> heights;
    for(int i=0;i<N;i++){
        int k; cin>>k;
        heights.push_back(k);
    }

    vector<int> dp(N,-1);

    cout<<frogJump(N,heights,dp)<<endl;
}

int frogJump(int n, vector<int> &heights, vector<int> &dp){
    if(n==1)
        return dp[0]=0;
    if(n==2)
        return dp[1]=abs(heights[1]-heights[0]);
    if(dp[n-1]!=-1)
        return dp[n-1];
    return dp[n-1]=min(frogJump(n-1,heights,dp)+abs(heights[n-1]-heights[n-2]), frogJump(n-2,heights,dp)+abs(heights[n-1]-heights[n-3]));
}