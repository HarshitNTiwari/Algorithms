/*
Author: Harshit Tiwari
Date: 01-04-2022
https://practice.geeksforgeeks.org/problems/ncr1019/1#
*/

// Tabulation based implementation

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int nCr(int n, int r);

int main(){
    int n; cin>>n;
    int r; cin>>r;

    cout<<nCr(n,r)<<endl;
}
 
int nCr(int n, int r){
    int M = 1000000007;
    // dp matrix to store answers for subproblems
    vector<vector<long long int>> dp(n+1, vector<long long int> (r+1,-1)); 

    if(r>n)
        return 0;
    for(int i=0;i<r+1;i++){
        dp[0][i]=0;    //Initialization of dp matrix
    }
    for(int i=0; i<n+1;i++){
        for (int j = 0; j <= min(i, r); j++) {
            if (j == 0 || j == i)
                dp[i][j] = 1;   //Initialization of dp matrix
            else
                dp[i][j]= (dp[i-1][j-1] + dp[i-1][j])%M;
        }
    }
    return dp[n][r];
}