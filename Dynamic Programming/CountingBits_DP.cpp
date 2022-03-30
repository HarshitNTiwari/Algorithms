/*
Author: Harshit Tiwari
Date: 21-02-2022
https://leetcode.com/problems/counting-bits/
*/

//This solution is the DP (bottom up) approach to the problem with complexity O(n).

#include <iostream>
#include <vector>
using namespace std;

vector<int> countBits(int n);

int main(){
    int n; cin>>n;
    vector<int> ans;
    ans = countBits(n);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}

vector<int> countBits(int n) {
    vector<int> ans(n+1,0);
    if(n==0)
        return ans;
    ans[1]=1;
    for(int i=2;i<=n;i++){
        ans[i]=(i%2)+ans[i/2];
    }
    return ans;
}