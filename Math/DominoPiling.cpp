//Author: Harshit Tiwari
//Date: 02-04-2021

// https://codeforces.com/problemset/problem/50/A

#include <iostream>
using namespace std;

int main(){
    int m,n,count; //count= no. of dominoes required
    cin>>m>>n;
    if((m*n)%2==0)
        count=(m*n)/2;
    else
        count=((m*n)-1)/2;

    cout<<count<<'\n';
    
   return 0; 
}