/*
Author: Harshit Tiwari
Date: 13-06-2022
https://practice.geeksforgeeks.org/problems/activity-selection-1587115620/1/
*/


class Solution
{
public:
    struct comp {
        template <typename T>

        // Comparator function
        bool operator()(const T& l, const T& r) const
        {
            if (l.second != r.second) {
                return l.second < r.second;
            }
            return l.first < r.first;
        }
    };
    //Function to find the maximum number of activities that can
    //be performed by a single person.
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        int count = 1;
        vector<pair<int, int>> activity;
        for (int i = 0; i < n; i++)
            activity.push_back(make_pair(start[i], end[i]));
        sort(activity.begin(), activity.end(), comp());
        int j = 0;
        for (int i = 1; i < activity.size(); i++) {
            if (activity[j].second < activity[i].first) {
                count++;
                j = i;
            }
        }
        return count;
    }
};