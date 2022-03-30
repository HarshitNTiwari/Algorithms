#include<iostream>
#include <vector>
using namespace std;
bool canJump(vector<int>& nums);
int main(){
    vector <int> nums;
    int n; cin>>n;
    for(int i=0;i<n;i++){
        int k; cin>>k;
        nums.push_back(k);
    }

    bool t = canJump(nums);
    cout<<t<<endl;
    return 0;
}

bool canJump(vector<int>& nums) {
    int n=nums.size();
    vector<int> dp(n,0);
    if(n==1)
        return true;
    dp[n-1]=1;
    dp[n-2]=(((n-2)+nums[n-2]>=n-1))?1:0;
    for(int i=n-3;i>=0;i--){
        for(int j=1;j<=(n-1-i);j++)
            if((i+nums[i]>=i+j) &&(dp[i+j]==1)){
                dp[i]=1;
                break;
            }
    }
    for(int i=0;i<dp.size();i++)
        cout<<dp[i]<<" ";
    cout<<endl;
    return (dp[0]==1?true:false); 
}

