/*
Author: Harshit Tiwari
Date: 26-06-2022
https://leetcode.com/problems/merge-intervals/
*/


class Solution { 
public:
    static bool sortbycol(const vector<int>& vec1, const vector<int>& vec2){
        return vec1[0] < vec2[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        // sorting intervals[] by start values using custom sort function
        sort(intervals.begin(), intervals.end(), sortbycol);
        int i = 0;
        while(i<intervals.size()-1){
            if(intervals[i][1] < intervals[i+1][0]){
                ans.push_back(intervals[i]);
            }
            else{
                intervals[i+1][0] = min(intervals[i][0], intervals[i+1][0]);
                intervals[i+1][1] = max(intervals[i][1], intervals[i+1][1]);
            }
            i++;
        }
        ans.push_back(intervals[intervals.size()-1]);
        return ans;
    }
};