/*
Author: Harshit Tiwari
Date: 16-06-2022
https://leetcode.com/problems/maximum-length-of-repeated-subarray/
*/

// This is solved using sliding window technique.

class Solution {
public:
    int checkwindow(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;
        int i1 = nums1.size() - 1;
        while (i1 >= 0) {
            int i2 = i1; int j = 0; int count = 0;
            while (i2 < nums1.size()) {
                if (nums1[i2] == nums2[j]) {
                    count++;
                    ans = max(ans, count);
                }
                else
                    count = 0;
                i2++;
                j++;
                if (j >= nums2.size())
                    break;
            }

            i1--;
        }
        return ans;
    }

    int findLength(vector<int>& nums1, vector<int>& nums2) {
        return max(checkwindow(nums1, nums2), checkwindow(nums2, nums1));
    }
};