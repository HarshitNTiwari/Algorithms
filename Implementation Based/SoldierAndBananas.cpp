// Author: Harshit Tiwari
// Date: 29-03-2021

// https://codeforces.com/problemset/problem/546/A

#include <iostream>
using namespace std;

int main(){
    int k,n,w,borrow=0;
    cin>>k>>n>>w;
    int cost=0;
    for(int i=1;i<=w;i++){
        cost=cost+(i*k);
    }
    if(cost>n) 
        borrow= cost-n;
    cout<<borrow<<'\n';

    return 0;
}