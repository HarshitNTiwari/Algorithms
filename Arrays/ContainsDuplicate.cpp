/*
Author: Harshit Tiwari
Date: 21-06-2022
https://leetcode.com/problems/contains-duplicate/
*/


class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> freq;
        for(auto& i: nums)
            freq[i]++;
        for(int i=0; i<nums.size(); i++){
            if(freq[nums[i]]>=2)
                return true;
        }
        return false;
    }
};