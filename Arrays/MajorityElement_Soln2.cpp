/*
Author: Harshit Tiwari
Date: 21-06-2022
https://leetcode.com/problems/majority-element/
*/

// Boyer Moore Voting Algorithm
// TC: O(n) and SC: O(1)

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans = 0, freq = 0;
        for(int i=0; i<nums.size(); i++){
            if(freq == 0){
                ans = nums[i];
                freq++;
            }
            else if(nums[i]==ans)
                freq++;
            else
                freq--;
        }
        return ans;
    }
};  