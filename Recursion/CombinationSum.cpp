/*
Author: Harshit Tiwari
Date: 13-08-2022
https://leetcode.com/problems/combination-sum/
*/

class Solution {
    void solve(vector<int>& candidates, int target, int sum, int begin, vector<vector<int>>& ans, vector<int>& temp){
        if(sum == target){
            ans.push_back(temp);
            return;
        }
        else if(sum > target){
            return;
        }
        if(begin == candidates.size())
            return;
        
        for(int i=begin; i<candidates.size(); i++){
            sum+=candidates[i];
            temp.push_back(candidates[i]);
            solve(candidates, target, sum, i, ans, temp);
            temp.pop_back();
            sum-=candidates[i];
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(candidates, target, 0, 0, ans, temp);
        return ans;
    }
};