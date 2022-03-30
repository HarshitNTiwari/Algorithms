/*
Author: Harshit Tiwari
Date: 21-02-2022
https://leetcode.com/problems/counting-bits/
*/

//This solution has time complexity as O(nlogn). 
//A better approach using DP with complexity O(n) also exists: See, CountingBits_DP.cpp

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
    for(int i=n;i>0;i--){
        int j=i;
        while (j>0){
            int k= j%2;
            if(k==1){
                ans[i]=ans[i]+1;
            }
            j=j/2;
        }
    }
    return ans;
}