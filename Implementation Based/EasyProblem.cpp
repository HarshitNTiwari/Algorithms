//Author: Harshit Tiwari 
//Date: 30-03-2021

// https://codeforces.com/problemset/problem/1030/A

#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> num;
    for(int i=0;i<n;i++){
        int k; cin>>k;
        num.push_back(k);
    }
    int flag=0;
    for(int i=0;i<n;i++){
        if(num[i]==1){
            flag=1;
            break;
        }
    }
    if(flag==0)
        cout<<"EASY"<<'\n';
    else if(flag==1)
        cout<<"HARD"<<'\n';

    return 0;
}