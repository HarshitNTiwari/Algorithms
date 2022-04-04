// Author: Harshit Tiwari
// Date; 29-03-2021

// https://codeforces.com/problemset/problem/59/A

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main(){
    string s;
    getline(cin,s);
    int upper=0,lower=0;
    for(int i=0;i<s.length();i++){
        if(isupper(s[i]))
            upper++;
        else
            lower++;
    }
    if(upper>lower){
        for(int i=0;i<s.length();i++){
            int c=s[i];
            s[i]=toupper(c);
        }
    }
    else if(lower>upper){
        for(int i=0;i<s.length();i++){
            int c=s[i];
            s[i]=tolower(c);
        }
    }
    else{
        for(int i=0;i<s.length();i++){
            int c=s[i];
            s[i]=tolower(c);
        }
    }
    cout<<s<<'\n';
    return 0;
}

