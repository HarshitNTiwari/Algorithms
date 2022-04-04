// Author: Harshit Tiwari
// Date: 29-03-2021

// https://codeforces.com/problemset/problem/112/A

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main(){
    string str1,str2;
    getline(cin,str1);
    getline(cin,str2);
    for(int i=0;i<str1.length();i++){
        int c=str1[i];
        str1[i]=toupper(c);  //Converting the entire string to upper case
    }
    for(int i=0;i<str2.length();i++){
        int c=str2[i];
        str2[i]=toupper(c);  //Converting the entire string to upper case
    }
    //Now, since both the strings are in same case, they can be compared directly
    if(str1>str2)
        cout<<1<<'\n';
    else if(str1<str2)
        cout<<-1<<'\n';
    else if(str1==str2)
        cout<<0<<'\n';

    return 0;
}