/*
Author: Harshit Tiwari
Date: 18-06-2022
https://leetcode.com/problems/minimum-difference-between-highest-and-lowest-of-k-scores/
*/


class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int ans = INT_MAX;
        sort(nums.begin(), nums.end());
        for (int i = 0; i <= nums.size() - k; i++) {
            ans = min(ans, nums[i + 1 + (k - 2)] - nums[i]);
        }
        return ans;
    }
};