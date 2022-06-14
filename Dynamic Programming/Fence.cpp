#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int solve(int n, int k, vector<int>& arr);

int main(){
    int n, k;
    cin>>n>>k;
    vector<int> arr;
    for(int i=0; i<n;i++){
        int k; cin>>k;
        arr.push_back(k);
    }

    cout<<solve(n,k,arr)<<endl;

    return 0;
}

int solve(int n, int k, vector<int>& arr){
    int ans =INT_MAX; 
    int x=INT_MAX;
    if(n==k)
        return 1;
    for(int i=k-1;i>=0;i--){
        ans= ans+ arr[i];
    }
    for(int i=k;i<n;i++){
        int temp=ans;
        ans = min(ans, ans-arr[i-k]+arr[i]);
        if(ans!=temp)
            x=min(x,i);
    }
    if(x<=0)
        return 1;
    return x-2+1;
}