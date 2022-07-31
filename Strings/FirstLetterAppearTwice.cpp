/*
Author: Harshit Tiwari
Date: 24-06-2022
https://leetcode.com/problems/first-letter-to-appear-twice/
*/


class Solution {
public:
    char repeatedCharacter(string s) {
        char c;
        unordered_map<char,int> mp;
        for(auto& i: s){
            if(mp.find(i)!=mp.end()){
                c = i;
                break;
            }
            mp[i]++;
        }
        return c;
    }
};