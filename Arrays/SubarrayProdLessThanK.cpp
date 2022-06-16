/*
Author: Harshit Tiwari
Date: 16-06-2022
https://leetcode.com/problems/subarray-product-less-than-k/
*/

// This is solved using sliding window technique.

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1)
            return 0;
        int p = 1; int count = 0; int ans = 0; int start = 0; int end = 0;
        for (int i = 0; i < nums.size(); i++) {
            p = p * nums[i]; end = i;
            if (p < k) {
                ans += count + 1;
                count++;
            }
            else {
                while (p >= k) {
                    p /= nums[start];
                    count--;
                    start++;
                }
                ans += count + 1;
                count++;
            }
        }
        return ans;
    }
};