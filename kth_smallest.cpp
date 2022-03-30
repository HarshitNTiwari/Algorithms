/*
Author: Harshit Tiwari
Date: 02-01-2022
Problem: https://practice.geeksforgeeks.org/problems/kth-smallest-element5635/1
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int kth_smallest(vector<int> v, int k,int &kth_smallest_element);

int main(){
    vector<int> v{9,2,8,3,6,4};
    int k;
    int kth_smallest_element;
    cin>>k;
    kth_smallest(v,k,kth_smallest_element);
    cout<<kth_smallest_element<<endl;
}

int kth_smallest(vector<int> v, int k,int &kth_smallest_element){
    sort(v.begin(),v.end());
    kth_smallest_element=v[k-1];
}