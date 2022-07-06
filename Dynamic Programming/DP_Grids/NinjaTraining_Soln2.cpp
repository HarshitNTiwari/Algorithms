/*
Author: Harshit Tiwari
Date: 03-07-2022
https://www.codingninjas.com/codestudio/problems/ninja-s-training_3621003
*/

// This is Tabulation (Bottom up) DP approach.

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

int solve(int n, vector<vector<int>> &points, vector<vector<int>>& dp) {
//'currtask' variable keeps track of which task is being done on the current day

    //Intialization of 1st row of DP matrix (i.e for 1st day):
    for (int currtask = 0; currtask < 3; currtask++) {
        dp[0][currtask] = points[0][currtask];
    }

    //from day 2 to day n : filling up the DP matrix
    for (int day = 1; day < n; day++) {
        for (int currtask = 0; currtask < 3; currtask++) {
            int maxi = 0;
            //checking for all the tasks on the prev day except for the task done on current day:
            //'prevtask' represents the task done on the prev day
            for (int prevTask = 0; prevTask < 3; prevTask++) {
                if (prevTask != currtask)
                    maxi = max (dp[day - 1][prevTask] , maxi);  //finding max from prev day
            }
            dp[day][currtask] = points[day][currtask] + maxi;  //adding max from prev day to points of curr day
            // dp[day][currtask] represents the max points achieved if task = 'currtask' is done on 'day'
        }
    }
    return max(dp[n - 1][0], max(dp[n - 1][1], dp[n - 1][2]));  //returning max of last row of DP matrix
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n, vector<int> (3, -1));
    return solve(n, points, dp);
}