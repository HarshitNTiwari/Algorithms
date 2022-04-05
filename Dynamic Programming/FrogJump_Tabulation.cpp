/*
Author: Harshit Tiwari
Date: 04-04-2022
https://www.codingninjas.com/codestudio/problems/frog-jump_3621012
*/

// Tabulation dynamic programming approach  

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

    cout<< frogJump(N,heights,dp)<<endl;
}

int frogJump(int n, vector<int> &heights, vector<int> &dp){
    dp[0]=0;    
    dp[1]=abs(heights[1]-heights[0]);   
    if(n==1)
        return dp[0];
    if(n==2)
        return dp[1];
    for(int i=3;i<=n;i++){
        dp[i-1]=min(dp[i-2]+abs(heights[i-1]-heights[i-2]), dp[i-3]+abs(heights[i-1]-heights[i-3]));
    }
    return dp[n-1];
}