/*
Author: Harshit Tiwari
Date: 12-09-2022
https://leetcode.com/problems/max-consecutive-ones-iii/
*/

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i = 0; int j = 0;
        int f = 0; int s = 0; int ans = INT_MIN;

        while (j < nums.size()) {
            if (nums[j] == 0) {
                f++;
            }
            s++;
            while (f > k && i <= j) {
                if (nums[i] == 0)
                    f--;
                s--;
                i++;
            }
            ans = max(ans, s);
            j++;
        }
        return ans;
    }
};