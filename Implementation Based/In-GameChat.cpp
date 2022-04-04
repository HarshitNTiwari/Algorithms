// Author: Harshit Tiwari
// Date: 30-03-2021

// https://codeforces.com/contest/1411/problem/A

#include <iostream>
#include <string>
using namespace std;

int main(){
    int t; cin>>t;
    for(int j=0;j<t;j++){
        int n; cin>>n;
        string str; cin>>str;
        int count=0;
        for(int i=str.length()-1;i>=0;i--){
            int flag=0;
            if(str[i]==')'){
                count++;
                if((i==0)||str[i-1]!=')')
                    flag=1;
            }
            if(flag==1){
                break;
            }
        }
        int rem=str.length()-count;
        if(count>rem)
            cout<<"Yes"<<'\n';
        else 
            cout<<"No"<<'\n';
    }

    return 0;
}