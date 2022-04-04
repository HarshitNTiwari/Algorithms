//Author: Harshit Tiwari
//Date: 02-03-2021

// https://codeforces.com/problemset/problem/339/A

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    string s; cin>>s; //taking input as string
    vector<int> vec;
    for(int i=0;i<s.length();i=i+2){//putting digits out of string in a vector vec
        int k=s[i]-'0';
        vec.push_back(k);
    }
    //sorting the digits in the vector using bubble sort
    for(int i=0;i<vec.size()-1;i++){
        for(int j=0;j<vec.size()-i-1;j++){
            if(vec[j]>vec[j+1]){
                int temp=vec[j];
                vec[j]=vec[j+1];
                vec[j+1]=temp;
            }
        }
    }
    //Printing the final answer
    for(int i=0;i<vec.size()-1;i++){
        cout<<vec[i]<<'+'; 
    }
    cout<<vec[vec.size()-1]<<'\n';
    return 0;
}