/*
Author: Harshit Tiwari
Date: 12-04-2022
Problem: https://codeforces.com/problemset/problem/1182/A
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int solve(int n);

int main(){
    int n; cin>> n;
    // vector<vector<int>> dp(3, vector<int> (n+1, -1));
    cout<<solve(n)<<endl;

    return 0;
}

int solve(int n){
    if(n%2!=0)
        return 0;
    int x = n/2;
    return pow(2,x);
}