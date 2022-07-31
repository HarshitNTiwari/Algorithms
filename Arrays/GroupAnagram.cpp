/*
Author: Harshit Tiwari
Date: 22-06-2022
https://leetcode.com/problems/group-anagrams/
*/

// TC : O(n) ; n = no. of strings in 'strs' array

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> ans; 
        
        for(int i=0; i<strs.size(); i++){
            string temp = strs[i];
            sort(temp.begin(), temp.end());  //this is going to take constant time
            if(mp.find(temp)==mp.end())
                mp.insert(pair<string, vector<string>>(temp, vector<string>()));   //inserting sorted form of a string as key
            mp[temp].push_back(strs[i]);                                           //inserting string with same sorted form as temp, as value
        }
        unordered_map<string, vector<string>>::iterator itr;
        for(itr=mp.begin(); itr!=mp.end(); itr++)
            ans.push_back(itr->second);
        return ans;
    }
};