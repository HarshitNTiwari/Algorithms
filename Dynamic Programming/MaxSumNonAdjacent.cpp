/*
Author: Harshit Tiwari
Date: 05-04-2022
https://www.codingninjas.com/codestudio/problems/maximum-sum-of-non-adjacent-elements_843261
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int MaxSum(int n, vector<int> &nums, vector<int> &dp);

int main(){
    int N; 
    cin>>N;
    vector<int> nums;
    for(int i=0;i<N;i++){
        int k; cin>>k;
        nums.push_back(k);
    }

    vector<int> dp(N,-1);

    cout<<MaxSum(N,nums,dp)<<endl;
}

int MaxSum(int n, vector<int> &nums, vector<int> &dp){
    if(n==1)
        return dp[0]=nums[0];
    if(n==2)
        return dp[1]=max(nums[0],nums[1]);
    if(dp[n-1]!=-1)
        return dp[n-1];
    return dp[n-1] = max(nums[n-1]+MaxSum(n-2,nums,dp) , MaxSum(n-1,nums,dp));
}