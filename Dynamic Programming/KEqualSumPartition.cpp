#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int countofSubsetSum(vector<int> arr, int sum, int n, vector<vector<int>>& dp);
bool canPartitionKSubsets(vector<int>& nums, int k);

int main(){
    int n;  cin>>n;            //Total number of nummbers in arr
    vector<int> arr;           //Given array of numbers
    for(int i=0;i<n;i++){
        int k; cin>>k;
        arr.push_back(k);
    } 
    int k;  cin>>k;    

    cout<<canPartitionKSubsets(arr,k)<<endl;

    return 0;
} 

int countofSubsetSum(vector<int> arr, int sum, int n, vector<vector<int>>& dp){
    //Initialization of dp matrix 
    for(int i=0;i<n+1;i++){
        for(int j=0;j<sum+1;j++){
            if(i==0||j==0)
                dp[i][j]=0;
            // if(j==0)
            //     dp[i][j]=1;
        }
    }

    //Iterative code for choice diagram:
    for(int i=1;i<n+1;i++){
        for(int j=1; j<sum+1; j++){
            if(arr[i-1]<=j)
                dp[i][j]= dp[i-1][j-arr[i-1]] + dp[i-1][j];
            else
                dp[i][j]= dp[i-1][j];
        }
    }
        
    return dp[n][sum];   //returning the last element of dp matrix
}

bool canPartitionKSubsets(vector<int>& nums, int k) {
    int n =nums.size();
    int sum=0;
    for(int i=0;i<nums.size();i++)
        sum=sum+nums[i];
    
    if(sum%k!=0)
        return false;
    
    vector<vector<int>> dp(n+1,vector<int>(sum+1, -1));
    
    int g=countofSubsetSum(nums,sum/k,n,dp);

    cout<<g<<endl;
    
    if(g==k)
        return true;
    else
        return false;
}