/*
Author: Harshit Tiwari
Date: 17-06-2022
https://leetcode.com/problems/longest-turbulent-subarray/
*/

// This is solved using sliding window technique.

class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int count = 1; int ans = 0; int g = 0; int s = 0; int temp = 0;
        if (arr.size() == 1)
            return arr.size();
        for (int i = 0; i < arr.size() - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                g++; s = 0;
                count++;
            }
            else if (arr[i] < arr[i + 1]) {
                s++; g = 0;
                count++;
            }
            else if (arr[i] == arr[i + 1]) {
                s = 0; g = 0;
                count = 1;
            }
            ans = max(ans, count);
            if (g > 1) {
                count = 2;
                ans = temp;
                g--;
            }
            if (s > 1) {
                count = 2;
                ans = temp;
                s--;
            }
            temp = ans;
        }
        return ans;
    }
};