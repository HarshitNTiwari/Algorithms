/*
Author: Harshit Tiwari
Date: 23-06-2022
https://leetcode.com/problems/insert-interval/
*/

// TC : O(n) ; n = no. of intervals in the 'intervals' array

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        
        // iterating through all the intervals in the 'intervals' array
        for(int i=0; i<intervals.size(); i++){
            if(newInterval[1] < intervals[i][0]){  //i.e. newInterval lies completely before intervals[i]
                ans.push_back(newInterval);
                while(i<intervals.size()){
                    ans.push_back(intervals[i]);
                    i++;
                }   
                return ans;
            }
            else if(newInterval[0] > intervals[i][1]){  //i.e. newInterval lies completely after intervals[i]
                ans.push_back(intervals[i]);
            }
            else{                                  //i.e. newInterval overlaps with intervals[i]
                newInterval[0] = min(intervals[i][0], newInterval[0]);
                newInterval[1] = max(intervals[i][1], newInterval[1]);
            }
        }
        
        ans.push_back(newInterval);

        return ans;
    }
};