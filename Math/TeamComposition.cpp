/*
Author: Harshit Tiwari
Date: 15-02-2022
https://codeforces.com/problemset/problem/1611/B
*/

//The following is a O(1) solution.

#include<iostream>
using namespace std;

void team();

int main(){
    int t; cin>>t;
    for(int i=0;i<t;i++){
        team();
    }
}

void team(){
    int a, b; cin>>a; cin>>b;
    int res=0;
    if(a<=b){
        if((a+b)/4<=a)
            res= (a+b)/4;
        else 
            res= a;
    }
    else{
        if((a+b)/4<=b)
            res= (a+b)/4;
        else 
            res= b;
    }
    cout<<res<<endl;
}