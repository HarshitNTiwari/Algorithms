/*
Author: Harshit Tiwari
Date: 26-03-2022
Problem: Equal Sum Partition Problem
*/

//Leetcode:https://leetcode.com/problems/partition-equal-subset-sum/submissions/

//Tabulation (Bottom-up approach) solution 

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool EqualSumPartition(vector<int> arr, int n);
bool SubsetSum(vector<int> arr, int Sum, int n, vector<vector<bool>> &dp);

int main(){
    int n;  cin>>n;         //Total number of nummbers in arr
    vector<int> arr;        //Given array of numbers
    for(int i=0;i<n;i++){
        int k; cin>>k;
        arr.push_back(k);
    } 
    
    cout<<EqualSumPartition(arr,n)<<endl;

    return 0;
} 

bool SubsetSum(vector<int> arr, int Sum, int n, vector<vector<bool>> &dp){
    //Initialization of dp matrix
    for(int i=0; i<n+1; i++){
        for(int j=0; j<Sum+1; j++){
            if(i==0) //i.e. n=0 i.e. arr is empty
                dp[i][j]=false;
            if(j==0) //i.e. Sum=0 
                dp[i][j]=true;
        }
    }

    // Iterative code for choice diagram:
    for(int i=1; i<n+1; i++){
        for(int j=1; j<Sum+1; j++){
            if(arr[i-1]<=j)
                dp[i][j]= dp[i-1][j-arr[i-1]] || dp[i-1][j];
            else 
                dp[i][j]= dp[i-1][j];
        }
    }

    return dp[n][Sum];  //returning the last element of dp matrix
}

bool EqualSumPartition(vector<int> arr, int n){
    int sum=0;        //To store sum of elements of arr
    for(int i=0; i<n; i++)
        sum=sum+arr[i];
    if(sum%2!=0)      //if sum is odd, we can't partition
        return false;
    else{
        //dp matrix to store answers for the subproblems initialized with true
        vector<vector<bool>> dp(n+1,vector<bool> (sum+1,true));
        return SubsetSum(arr, sum/2, n, dp);
    }
}