/*
Author: Harshit Tiwari
Date: 19-07-2022
https://leetcode.com/problems/two-sum/
*/


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> index;
        for(int i=0; i<nums.size(); i++)
            index.insert({nums[i], i});
        
        vector<int> ans;
        for(int i=0; i<nums.size(); i++){
            int comp = target - nums[i];
            if(index.find(comp) != index.end() && i != index[comp]){
                ans.push_back(i);
                ans.push_back(index[comp]);
                break;
            }
        }
        return ans;
    }
};