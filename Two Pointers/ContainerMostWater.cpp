/*
Author: Harshit Tiwari
Date: 14-08-2022
https://leetcode.com/problems/container-with-most-water/
*/


class Solution {
public:
    int M = 1e9 + 7;
    int maxArea(vector<int>& height) {
        long i=0, j=height.size()-1; int maxWater = INT_MIN;
        while(i < j){
            if(height[i] <= height[j]){
                long amount = ((j-i)*height[i]) % M;
                int water = amount;
                maxWater = max(maxWater, water);
                i++;
            }
            else if(height[j] < height[i]){
                long amount = ((j-i)*height[j]) % M;
                int water = amount;
                maxWater = max(maxWater, water);
                j--;
            }
        }
        return maxWater;
    }
};