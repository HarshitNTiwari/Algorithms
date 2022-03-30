/*
Author: Harshit Tiwari
Date: 26-03-2022
Problem: 01 KnapSack Problem
*/

//Recursive and memoized (Top-Down approach) solution

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int KnapSack(vector<int> wt, vector<int> val, int W, int n, vector<vector<int>> &dp);

int main(){
    int n;  cin>>n;           //Total number of items 
    int W;  cin>>W;           //Maximum Capacity of the KnapSack
    //dp matrix to store answers for the subproblems initialized with -1
    vector<vector<int>> dp(n+1,vector<int> (W+1,-1));

    vector<int> wt;           //Array containing weights of the items
    for(int i=0;i<n;i++){
        int k; cin>>k;
        wt.push_back(k);
    }
    vector<int> val;         //Array containing values of the items
    for(int i=0;i<n;i++){
        int k; cin>>k;
        val.push_back(k);
    }
    
    cout<<KnapSack(wt,val,W,n,dp)<<endl;

    return 0;
} 

//Recursive and memoized function for 01 KnapSack problem
int KnapSack(vector<int> wt, vector<int> val, int W, int n, vector<vector<int>> &dp){

    //Base condition of recursive function
    if(n==0||W==0)   //this is the smallest possible input
        return 0;

    //Checking if the answer is already present in the dp matrix
    if(dp[n][W]!=-1)         //i.e answer is already present
        return dp[n][W];     //answer is returned
    
    //if the answer isn't already present in the dp matrix, we'll compute it.
    //recursive code for the choice diagram :
    if(wt[n-1]<=W)
        return dp[n][W]=max(val[n-1]+KnapSack(wt,val,W-wt[n-1],n-1,dp),KnapSack(wt,val,W,n-1,dp));
    else if(wt[n-1]>W)
        return dp[n][W]=(KnapSack(wt,val,W,n-1,dp));
}