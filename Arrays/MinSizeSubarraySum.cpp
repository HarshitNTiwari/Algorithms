/*
Author: Harshit Tiwari
Date: 14-06-2022
https://leetcode.com/problems/minimum-size-subarray-sum/
*/

// This is solved using sliding window technique. Note, here that the size of the window is varying.

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum1 = 0; int ans = INT_MAX; int n = 0; int start = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum1 += nums[i];
            n++;  //size of the window increased by one
            while (sum1 >= target) {
                ans = min(ans, n);
                sum1 -= nums[start];   //1st element reduced from sum
                n--;   //size of window reduced by one
                if (sum1 >= target)
                    ans = min(ans, n);
                start++;
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};