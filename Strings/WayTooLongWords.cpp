// Author: Harshit Tiwari
// Date: 27-03-2021

//https://codeforces.com/problemset/problem/71/A

#include<iostream>
#include<string>
using namespace std;
void check();
int main(){
    int n;
    cin>>n;
    cin.ignore(2,'\n'); //To ignore a new line character that is unnecessarily coming.
    for(int i=0;i<n;i++){
        check();
    }
    return 0;
}

void check(){
    string str;
    getline(cin,str);
    int length=str.length();
    if(length>10)
        cout<<str[0]<<(length-2)<<str[length-1]<<'\n';
    else
        cout<<str<<'\n';
    
    return;
}
