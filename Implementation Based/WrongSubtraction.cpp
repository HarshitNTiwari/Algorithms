//Author: Harshit Tiwari 
// Date: 30-03-2021

// https://codeforces.com/problemset/problem/977/A

#include <iostream>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    for(int i=0;i<k;i++){
        if(n%10==0){
            n=n/10;
        }
        else 
            n=n-1;
    }
    cout<<n<<'\n';
    return 0;
}