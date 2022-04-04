//Author: Harshit Tiwari
//Date: 25-08-2021

//https://codeforces.com/problemset/problem/445/A

#include <iostream>
#include <vector>
using namespace std;

void chessBoard(){
    int n,m;
    cin>>  n>> m;
    vector<vector<char>> vec(n, vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>> vec[i][j];
            if(vec[i][j] == '.'){
                if((i%2==0 && j%2==0)||(i%2!=0 && j%2!=0))
                    vec[i][j]='W';
                else 
                    vec[i][j]='B';
            }
        }
    }

//Printing the output positions
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<vec[i][j];
        }
        cout<<"\n";
    }
    
}

int main(){
    chessBoard();
    return 0;
}