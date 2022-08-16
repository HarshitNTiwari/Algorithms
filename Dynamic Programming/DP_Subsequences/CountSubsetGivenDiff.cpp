/*
Author: Harshit Tiwari
Date: 30-03-2022
Problem: Count the number of subsets with a given difference
        Exactly same problem, with different language: https://leetcode.com/problems/target-sum/
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int countofSubsetSum(vector<int> arr, int sum, int n, vector<vector<int>>& dp);
int CountSubsetGivenDiff(vector<int> arr, int n, int diff);

int main(){
    int n;  cin>>n;            //Total number of nummbers in arr
    vector<int> arr;           //Given array of numbers
    for(int i=0;i<n;i++){
        int k; cin>>k;
        arr.push_back(k);
    }   

    int diff; cin>>diff;

    cout<<CountSubsetGivenDiff(arr,n,diff)<<endl;

    return 0;
} 

int countofSubsetSum(vector<int> arr, int sum, int n, vector<vector<int>>& dp){
    //Initialization of dp matrix 
    for(int i=0;i<n+1;i++){
        for(int j=0;j<sum+1;j++){
            if(i==0)
                dp[i][j]=0;
            if(j==0)
                dp[i][j]=1;
        }
    }

    //Iterative code for choice diagram:
    for(int i=1;i<n+1;i++){
        for(int j=0; j<sum+1; j++){
            if(arr[i-1]<=j)
                dp[i][j]= dp[i-1][j-arr[i-1]] + dp[i-1][j];
            else
                dp[i][j]= dp[i-1][j];
        }
    }

    return dp[n][sum];   //returning the last element of dp matrix
}

int CountSubsetGivenDiff(vector<int> arr, int n, int diff){
    int sum=0;  
    for(int i=0;i<n;i++)
        sum=sum+arr[i];

    if(diff>sum || ((sum+diff)/2)<0 || (sum+diff)%2!=0)
        return 0;

    vector<vector<int>> dp(n+1,vector<int> (((sum+diff)/2)+1,-1));
    int k= countofSubsetSum(arr,(sum+diff)/2,n,dp);

    if(k==-1)
        return 0;
    else 
        return k;
}