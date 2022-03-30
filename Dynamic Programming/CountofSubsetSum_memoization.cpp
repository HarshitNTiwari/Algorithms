/*
Author: Harshit Tiwari
Date: 26-03-2022
Problem: Count of Subset Sum
*/

//Memoization (Top-down approach) solution

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int countofSubsetSum(vector<int> arr, int sum, int n, vector<vector<int>> &dp);

int main(){
    int n; cin>> n;
    vector<int> arr;           //Given array of numbers
    for(int i=0;i<n;i++){
        int k; cin>>k;
        arr.push_back(k);
    } 
    int Sum; cin>>Sum;

    //dp matrix to store answers for the subproblems initialized with -1
    vector<vector<int>> dp(n+1,vector<int> (Sum+1,-1));

    cout<< countofSubsetSum(arr, Sum, n, dp)<<endl;
}

int countofSubsetSum(vector<int> arr, int sum, int n, vector<vector<int>> &dp){
    // Base Condition
    if(sum==0)
        return 1;
    if(n==0)
        return 0;
    
    if(dp[n][sum]!=-1)
        return dp[n][sum];

    //Recursive code:
    if(arr[n-1]<=sum)
        dp[n][sum]= countofSubsetSum(arr,sum-arr[n-1],n-1,dp)+ countofSubsetSum(arr,sum,n-1,dp);
    else 
        dp[n][sum]= countofSubsetSum(arr,sum,n-1,dp);

    return dp[n][sum];
}