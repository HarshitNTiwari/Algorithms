/*
Author: Harshit Tiwari
Date: 13-08-2022
https://leetcode.com/problems/permutations/
*/


class Solution {
    void permutations(vector<int>& nums, int begin, vector<vector<int>>& ans){
        if(begin == nums.size()){
            ans.push_back(nums);
            return;
        }
        
        for(int i= begin; i<nums.size(); i++){
            swap(nums[i], nums[begin]);
            permutations(nums, begin+1, ans);
            swap(nums[i], nums[begin]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        permutations(nums, 0, ans);
        return ans;
    }
};