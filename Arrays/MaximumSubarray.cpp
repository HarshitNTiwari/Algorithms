/*
Author: Harshit Tiwari
Date: 20-07-2022
https://leetcode.com/problems/maximum-subarray/
*/


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int ans = INT_MIN;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]+sum >= nums[i]){
                sum+=nums[i]; 
            }
            else{
                sum = nums[i];
            }
            ans = max(ans, sum);
        }
        return ans;
    }
};