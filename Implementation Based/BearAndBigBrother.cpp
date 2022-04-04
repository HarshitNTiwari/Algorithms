// Author: Harshit Tiwari
// Date: 30-03-2021

// https://codeforces.com/problemset/problem/791/A

#include <iostream>
using namespace std;

int main(){
    int l,b,count=0;
    cin>>l>>b;
    while(l<=b){
        l=l*3;
        b=b*2;
        count++;
    }
    cout<<count<<'\n';

    return 0;
}