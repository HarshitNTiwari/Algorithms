//Author: Harshit Tiwari
//Date; 09-04-2021

//https://codeforces.com/problemset/problem/381/A

#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n; cin>>n;
    vector<int> nums;
    for(int i=0;i<n;i++){
        int k; cin>>k;
        nums.push_back(k);
    }

    int s=0,d=0;
    int l,r;
    l=0;
    r=nums.size()-1;
    if(l==r){
        s=nums[0];
        d=0;
        cout<<s<<' '<<d;
    }
    else{
        vector<int> res;
        while(l<=r){
            if(nums[l]>nums[r]){
                int k=nums[l];
                res.push_back(k);
                l++;
            }
            else{
                int k=nums[r];
                res.push_back(k);
                r--;
            }     
        }
        for(int i=0;i<res.size();i+=2){
            s=s+res[i];
        }
        for(int i=1;i<res.size();i+=2){
            d=d+res[i];
        }
        cout<<s<<' '<<d;
    }

    return 0;
}