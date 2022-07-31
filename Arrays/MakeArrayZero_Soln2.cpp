/*
Author: Harshit Tiwari
Date: 31-06-2022
https://leetcode.com/problems/make-array-zero-by-subtracting-equal-amounts/
*/

// TC: o(n) SC: O(n)

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_map<int, int> mp;
        int count = 0;
        for(int i=0; i<nums.size(); i++){
        	// answer is the no. of unique non-zero elements in the array
            if(nums[i] != 0 && mp.find(nums[i]) == mp.end()){
                mp[nums[i]]++;
                count++;
            }   
        }
        return count;
    }
};