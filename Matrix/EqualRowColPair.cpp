/*
Author: Harshit Tiwari
Date: 24-06-2022
https://leetcode.com/problems/equal-row-and-column-pairs/
*/


class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        unordered_map<string, int> mp;
        int count =0;
        
        for(int i=0; i<grid.size(); i++){
            vector<int> vec;
            for(int j =0; j<grid.size(); j++){
                vec.push_back(grid[i][j]);
            }
            stringstream ss;
            copy( vec.begin(), vec.end(), ostream_iterator<int>(ss, " "));
            string s = ss.str();
            mp[s]++;
        }
        
        
        for(int j=0; j<grid.size(); j++){
            vector<int> vec;
            for(int i=0; i<grid.size(); i++){
                vec.push_back(grid[i][j]);
            }
            stringstream ss;
            copy( vec.begin(), vec.end(), ostream_iterator<int>(ss, " "));
            string s = ss.str();
            if(mp.find(s)!=mp.end())
                count += mp[s];
        }
        
        return count;
    }
};