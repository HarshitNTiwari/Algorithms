//Author: Harshit Tiwari 
//Date: 02-04-2021

// https://codeforces.com/problemset/problem/263/A

#include <iostream>
#include <vector>
#include <cstdlib> //for abs()
using namespace std;

int main(){
    vector<vector<int>> matrix(5,vector<int>(5));
    //for input matrix
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            int k; cin>>k;
            matrix[i][j]=k;
        }
    }
    //to find '1' in the matrix
    int m,n,count=0;
    for(int i = 0; i < 5; i++){
        int flag=0;
        for(int j = 0; j < 5; j++){
            if(matrix[i][j]==1){
                m=i+1; //to store the row no. of 1
                n=j+1; //to store the column no. of 1
                flag =1;
                break;
            }
        }
        if(flag==1){
            break;
        }
    }
    count=abs(3-m)+abs(3-n); //no. of swaps required

    cout<<count<<'\n';
    
    return 0;
}