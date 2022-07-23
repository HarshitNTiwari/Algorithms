/*
Author: Harshit Tiwari
Date: 21-06-2022
https://leetcode.com/problems/majority-element/
*/
	
// TC: O(n) and SC: O(n)
// A better solution with O(1) SC exists.

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> freq;
        int n = nums.size();
        for(auto& i: nums)
            freq[i]++;
        for(int i=0; i<nums.size(); i++){
            if(freq[nums[i]]>(n/2))
                return nums[i];
        }
        return -1;
    }
};