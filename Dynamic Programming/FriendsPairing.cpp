/*
Author: Harshit Tiwari
Date: 02-04-2022
https://practice.geeksforgeeks.org/problems/friends-pairing-problem5425/1#
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int countFriendsPairings(int n);

int main(){
    int n; cin>>n;
    cout<< countFriendsPairings(n)<<endl; 
}

int countFriendsPairings(int n){
    int M= 1000000007;
    vector<int> dp(n+1,0);
    dp[1]=1;
    dp[2]=2;
    for(long long int i=3;i<=n;i++){
        dp[i]= ((dp[i-1])%M+ ((i-1)*dp[i-2])%M)%M;
    }
    return (dp[n])%M;
}