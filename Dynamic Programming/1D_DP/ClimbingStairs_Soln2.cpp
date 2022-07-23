/*
Author: Harshit Tiwari
Date: 04-04-2022
https://leetcode.com/problems/climbing-stairs/submissions/
*/

// Tabulation (bottom up) DP approach

class Solution {
public:
    int climbStairs(int n) {
        vector<int> memo(n,-1);
        
        //initializaton:
        memo[0] = 1;
        if(n==1)
            return memo[0];
        memo[1] = 2;
        if(n==2)
            return memo[1];
        
        for(int step = 3; step<=n; step++){
            memo[step-1] = memo[step-2] + memo[step-3];
        }
        return memo[n-1];
    }
};