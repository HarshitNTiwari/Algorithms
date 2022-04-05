#include <iostream>
/*
Author: Harshit Tiwari
Date: 05-04-2022
https://www.codingninjas.com/codestudio/problems/ninja-s-training_3621003
*/

#include <vector>
#include <algorithm>

using namespace std;

int solve(int n, int task, vector<vector<int>> &points, vector<vector<int>> &dp);
int ninjaTraining(int n, vector<vector<int>> &points);
int maxN(int n, int m, int k);

int main(){
    int n; cin>>n;
    vector<vector<int>> points;
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            int k; cin>>k;
            points[i].push_back(k);
        }
    }

    cout<< ninjaTraining(n, points) <<endl;

    return 0;
}


int solve(int n, int task, vector<vector<int>>& points, vector<vector<int>>& dp){
    if(n==1){
        dp[0][0]= points[0][0];
        dp[0][1]= points[0][1];
        dp[0][2]= points[0][2];
        return dp[0][task];
    }
    int z=0;
    int y=0;
    if(task==0){
        y=1; z=2;
    }
    if(task==1){
        y=0; z=2;
    }
    if(task==2){
        y=0; z=1;
    }
    if(dp[n-1][task]!=-1)
        return dp[n-1][task];
    return dp[n-1][task] =  points[n-1][task]+ max(solve(n-1,y,points,dp),solve(n-1,z,points,dp));
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n, vector<int> (3,-1));
    
    dp[n-1][0] = solve(n-1,0,points,dp);
    dp[n-1][1] = solve(n-1,1,points,dp);
    dp[n-1][2] = solve(n-1,2,points,dp);
   	
    int ans=0;
  	for(int i=0; i<3; i++){
        ans = max(ans, dp[n-1][i]);
    }
    return ans;
}