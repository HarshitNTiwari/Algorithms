/*
Author: Harshit Tiwari
Date: 04-04-2022
https://leetcode.com/problems/climbing-stairs/submissions/
*/

//Recursive and Memoized (Top-down approach) solution

class Solution {
    int solve(int n, vector<int>& memo){

        //Base conditions:
        if(n==1) //for the 1st stair
            return memo[0] = 1;
        if(n==2) //for the 2nd stair
            return memo[1] = 2;
        
        if(memo[n-1]!=-1)
            return memo[n-1];
        
        return memo[n-1] = solve(n-1, memo) + solve(n-2, memo);
    }
public:
    int climbStairs(int n) {
        if(n==1)
            return 1;
        if(n==2)
            return 2;
        
        vector<int> memo(n,-1);
        
        return memo[n-1] = solve(n-1, memo) + solve(n-2, memo);
    }
};