/*
Author: Harshit Tiwari
Date: 15-02-2022
https://codeforces.com/problemset/problem/750/A
*/

//The following is O(n) solution. A O(log n) solution using binary search also exists.
#include<iostream>
using namespace std;

int main(){
    int n,k; cin>>n; cin>>k;
    int time=0,res=0;
    for(int i=1;i<=n;i++){
        time= time+(5*i);
        if(time<=(240-k))
            res=i;
        else
            break;
    }
    cout<<res;
    return 0;
}