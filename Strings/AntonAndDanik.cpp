//Author: Harshit Tiwari 
// Date: 30-03-2021

// https://codeforces.com/problemset/problem/734/A

#include <iostream>
#include <string>

using namespace std;

int main(){
    int n,a=0,d=0;    cin>>n;
    string str; cin>>str;
    for(int i=0;i<str.length();i++){
        if(str[i]=='A')
            a++;
        else 
            d++;
    }
    if(a>d)
        cout<<"Anton"<<'\n';
    else if(d>a)
        cout<<"Danik"<<'\n';
    else if(a==d)
        cout<<"Friendship"<<'\n';

    return 0;
}