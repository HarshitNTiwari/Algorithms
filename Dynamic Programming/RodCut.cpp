/*
Author: Harshit Tiwari
Date: 31-03-2022
https://practice.geeksforgeeks.org/problems/rod-cutting0840/1#
*/

//Tabulation (Bottom-up approach) solution
 
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int RodCut(vector<int> price, int n, vector<vector<int>> &dp);

int main(){
    int n;  cin>>n;      
    
    //dp matrix to store answers for the subproblems initialized with -1
    vector<vector<int>> dp(n+1,vector<int> (n+1,-1));

    vector<int> price;          //Array containing prices 
    for(int i=0;i<n;i++){
        int k; cin>>k;
        price.push_back(k);
    }
    
    cout<<RodCut(price,n,dp)<<endl;

    return 0;
} 


int RodCut(vector<int> price, int n, vector<vector<int>> &dp){

    vector<int> len;
    for(int i=1;i<=n;i++){
        len.push_back(i);
    }
    
    // Initialization of dp matrix
    for(int i=0;i<n+1;i++){
        dp[0][i]=0;
    }
    for(int i=0;i<n+1;i++){
        dp[i][0]=0;
    }
    
    for(int i=1;i<n+1;i++){
        for(int j=1;j<n+1;j++){
            if(len[i-1]<=j)
                dp[i][j]= max(price[i-1]+dp[i][j-len[i-1]], dp[i-1][j]);
            else
                dp[i][j]= dp[i-1][j];
        }
    }
    
    return dp[n][n];
}