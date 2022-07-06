/*
Author: Harshit Tiwari
Date: 03-07-2022
https://www.codingninjas.com/codestudio/problems/ninja-s-training_3621003
*/

// This is Tabulation (Bottom up) DP approach --- Space Optimization

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

int solve(int n, vector<vector<int>> &points, vector<int>& dp) {
//'currtask' variable keeps track of which task is being done on the current day

    //Intialization of DP array (i.e for 1st day):
    for (int currtask = 0; currtask < 3; currtask++) {
        dp[currtask] = points[0][currtask];
    }

    //from day 2 to day n :
    for (int day = 1; day < n; day++) {
        vector<int> temp(3, -1); //for storing values for current day
        for (int currtask = 0; currtask < 3; currtask++) {
            int maxi = 0;
            //checking for all the tasks on the prev day except for the task done on current day:
            //'prevtask' represents the task done on the prev day
            for (int prevTask = 0; prevTask < 3; prevTask++) {
                if (prevTask != currtask)
                    maxi = max (dp[prevTask] , maxi);  //finding max from prev day
            }
            temp[currtask] = points[day][currtask] + maxi;  //adding max from prev day to points of curr day
            // temp[currtask] represents the max points achieved if task = 'currtask' is done on 'day'
        }
        dp = temp;
    }
    return max(dp[0], max(dp[1], dp[2]));  //returning max of the values in DP array
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<int> dp(3, -1);  //using a 1D array instead of a 2D matrix
    return solve(n, points, dp);
}