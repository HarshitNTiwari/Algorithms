/*
Author: Harshit Tiwari
Date: 01-04-2022
https://practice.geeksforgeeks.org/problems/nth-catalan-number0817/1
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long int NthCatalan(int n);

int main(){
    int n; cin>>n;
    cout<<NthCatalan(n)<<endl;

    return 0;
}

long long int NthCatalan(int n){
    vector<long long int> dp(n+1,-1);
    if(n==0 || n==1)
        return 1;
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<n+1;i++){
        dp[i]=0;
        for(int j=0;j<i;j++){
            dp[i]= dp[i]+ (dp[j]*dp[(i-1)-j]);
        }
    }
    return dp[n];
}