/*
Author: Harshit Tiwari
Date: 23-06-2022
https://leetcode.com/problems/product-of-array-except-self/
*/


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
        
        //calculating prefix products and storing in ans[]
        int prefix = 1;
        for(int i=0; i<nums.size(); i++){
            ans.push_back(prefix);
            prefix*= nums[i];
        }
        
        //calculating postfix products and multiplying with the already existing prefix products in ans[]
        int postfix = 1;
        for(int i=nums.size()-1; i>=0; i--){
            ans[i]*=postfix;
            postfix*=nums[i];
        }
        
        return ans;
    }
};