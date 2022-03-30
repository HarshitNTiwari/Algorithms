/*
Author: Harshit Tiwari
Date: 01-01-2022
Problem: Find the maximum and minimum element in an array.
*/

//Time complexity of this approach is O(n).

#include<iostream>
#include<vector>
using namespace std;

vector<int> maxmin(vector<int> v,vector<int> &res);

int main(){
    vector<int> v{20,10,30,7,50,122,3};
    vector<int> res;
    maxmin(v,res);
    cout<<"The Maximum element is: "<<res[0]<<endl;
    cout<<"The minimum element is: "<<res[1]<<endl;
}

vector<int> maxmin(vector<int> v,vector<int> &res){
    int max=v[0];
    for(int i=1;i<v.size();i++)
        if(v[i]>max)
            max=v[i];
    res.push_back(max);

    int min=v[0];
    for(int i=1;i<v.size();i++)
        if(v[i]<min)
            min=v[i];
    res.push_back(min);
}