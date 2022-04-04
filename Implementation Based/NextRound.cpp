// Author: Harshit Tiwari
// Date: 29-03-2021

//https://codeforces.com/problemset/problem/158/A

#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n,k,count=0;
    string str;
    cin>>n>>k;
    cin.ignore(2,'\n');
    vector<int> scores;
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        scores.push_back(k);
    }
    for(int i=0;i<n;i++){
        if ((scores[i]>0)&&(scores[i]>=scores[k-1]))
            count++;
    }

    cout<<count<<'\n'; //No. of contestants advancing to next round
    return 0;
}