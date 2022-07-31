/*
Author: Harshit Tiwari
Date: 31-06-2022
https://leetcode.com/problems/make-array-zero-by-subtracting-equal-amounts/
*/

// TC: o(nlogn)  SC: O(1)

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int count = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]!=0){
                int k = nums[i];
                for(int j=i; j<nums.size(); j++){
                    nums[j]-=k;
                }
                count++;
            }
        }
        return count;
    }
};