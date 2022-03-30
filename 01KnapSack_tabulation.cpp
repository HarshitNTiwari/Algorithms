/*
Author: Harshit Tiwari
Date: 26-03-2022
Problem: 01 KnapSack Problem
*/

//Tabulation (Bottom-up approach) solution  

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
    vector<int> val;          //Array containing values of the items
    for(int i=0;i<n;i++){
        int k; cin>>k;
        val.push_back(k);
    }
    
    cout<<KnapSack(wt,val,W,n,dp)<<endl;

    return 0;
} 

//Tabulation function for 01 KnapSack problem
int KnapSack(vector<int> wt, vector<int> val, int W, int n, vector<vector<int>> &dp){

    //Initialization of dp matrix
    for(int i=0;i<n+1;i++)
        for(int j=0;j<W+1;j++)
            if(i==0 || j==0) //i.e. if either n=0 or W=0 
                dp[i][j]=0;

    //Iterative code for choice diagram: 
    for(int i=1; i<n+1;i++){
        for(int j=1;j<W+1;j++)
            if(wt[i-1]<=j)
                dp[i][j]= max(val[i-1]+dp[i-1][j-wt[i-1]], dp[i-1][j]);
            else
                dp[i][j]= dp[i-1][j];
    }
    return dp[n][W];  //returning the last element of dp matrix
}