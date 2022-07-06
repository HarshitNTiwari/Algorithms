/*
Author: Harshit Tiwari
Date: 05-04-2022
https://www.codingninjas.com/codestudio/problems/ninja-s-training_3621003
*/

// This is memoization (Top down) DP approach.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solve(int n, int currtask, vector<vector<int>> &points, vector<vector<int>> &dp);
int ninjaTraining(int n, vector<vector<int>> &points);

int main() {
    int n; cin >> n;
    vector<vector<int>> points;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            int k; cin >> k;
            points[i].push_back(k);
        }
    }

    cout << ninjaTraining(n, points) << endl;

    return 0;
}

int solve(int n, int currtask, vector<vector<int>>& points, vector<vector<int>>& dp) {
//'currtask' variable keeps track of which task is being done on the current day

    // Base condition: 1st day
    if (n == 1) {
        return dp[0][currtask] = points[0][currtask];
    }

    if (dp[n - 1][currtask] != -1)
        return dp[n - 1][currtask];

    // here we solve that if task = 'currtask' is done on current day then, what would be the max points achieved:

    //iterating in the previous day for all the tasks except for the task being performed on current day:
    int maxi = 0;
    for (int prevtask = 0; prevtask < 3; prevtask++) {
        //'prevtask' represents the task done on the prev day
        if (prevtask != currtask) {
            maxi = max(solve(n - 1, prevtask , points, dp), maxi);
        }
    }
    return dp[n - 1][currtask] =  points[n - 1][currtask] + maxi;
    // dp[n-1][currtask] represents the max points achieved if task = 'currtask' is done on nth day
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n, vector<int> (3, -1));

    // calculating values of the last row of dp matrix (i.e for the last day):
    for (int currtask = 0; currtask < 3; currtask++) {
        int maxi = 0;
        //iterating in the previous day for all the tasks except for the currtask being performed on current day:
        for (int prevtask = 0; prevtask < 3; prevtask++) {
            //'prevtask' represents the task done on the prev day
            if (prevtask != currtask) {
                // recursive call for previous day to find max points earned from prev day:
                maxi = max(solve(n - 1, prevtask, points, dp), maxi);
            }
        }
        dp[n - 1][currtask] = points[n - 1][currtask] + maxi;
    }
    //returning the max from last row:
    return max(dp[n - 1][0], max(dp[n - 1][1], dp[n - 1][2]));
}