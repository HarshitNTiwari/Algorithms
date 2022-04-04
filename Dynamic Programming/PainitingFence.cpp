/*
Author: Harshit Tiwari
Date: 03-04-2022
https://practice.geeksforgeeks.org/problems/painting-the-fence3727/1#
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long countWays(int n, int k);

int main(){
    int n; cin>>n;
    int k; cin>>k;

    cout<<countWays(n,k)<<endl;
}

long long countWays(int n, int k){
    long long int M= 1000000007;
    vector<vector<long long int>> dp(n+1,vector<long long int> (k+1,0));

    if(n==1)
        return k%M;
    if(n==2)
        return (k*k)%M;
    if(n>2 && k==1)
        return 0;

    for(int i=1;i<=k;i++){
        dp[1][i]=(i)%M;
        dp[2][i]=(i*i)%M;
    }
    for(int i=3;i<=n;i++){
        dp[i][1]=0;
    }
    
    for(int i=3;i<=n;i++){
        for(int j=2;j<=k;j++){
            dp[i][j]=(((dp[i-1][j])%M+ (dp[i-2][j])%M)*(j-1))%M;
        }
    }
        
    return (dp[n][k])%M;
}