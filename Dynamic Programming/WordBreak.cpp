/*
Author: Harshit Tiwari
Date: 14-08-2022
https://leetcode.com/problems/word-break/
*/

// Recusrive and memoized code

class Solution {
    bool solve(string s, int start, vector<string>& wordDict, vector<int>& dp){
        if(start >= s.size())
            return true;
        if(dp[start] != -1)
            return dp[start];
        bool ans = false;
        for(int i=0; i<wordDict.size(); i++){
            if(s.substr(start, wordDict[i].size()) == wordDict[i]){
                ans = ans || solve(s, start+wordDict[i].size(), wordDict, dp);
                dp[start] = ans;
            }
        }
        return dp[start] = ans;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.size(), -1);
        return solve(s, 0, wordDict, dp);
    }
};