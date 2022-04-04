/*
Author: Harshit Tiwari
Date: 02-04-2022
https://www.geeksforgeeks.org/permutation-coefficient/
*/

// This is the dynamic programming approach. Simpler implementations exist.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long int nPr(int n,int r);

int main(){
    int n; cin>>n;
    int r; cin>>r;
    cout<<nPr(n,r)<<endl;

    return 0;
}

long long int nPr(int n,int r){
    vector<vector<long long int>> dp(n+1, vector<long long int> (r+1,0));
    if(r>n)
        return 0;
    for(int i=0;i<r+1;i++){
        dp[0][i]=0;
    }
    dp[0][0]=1;
    for(int i=1; i<n+1;i++){
        for(int j=0; j<=min(i,r); j++){
            if(j==0)
                dp[i][j]=1;
            else 
                dp[i][j]= j*dp[i-1][j-1] + dp[i-1][j];
        }
    }
    return dp[n][r];
}