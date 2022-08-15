/*
Author: Harshit Tiwari
Date: 15-08-2022
https://leetcode.com/problems/sort-colors/
*/

// Simple Bubble sort

class Solution {
public:
    void sortColors(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++){
            for(int j=i+1; j<nums.size(); j++){
                if(nums[i] > nums[j]){
                    swap(nums[j], nums[i]);
                }
            }
        }
    }
};