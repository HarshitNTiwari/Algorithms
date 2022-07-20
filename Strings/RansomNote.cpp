/*
Author: Harshit Tiwari
Date: 20-07-2022
https://leetcode.com/problems/ransom-note/
*/

// This problem is almost similar to LC 242. Valid Anagram

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> mp;
        for(auto& i: magazine)
            mp[i]++;
        for(int i=0; i<ransomNote.size(); i++){
            if(mp.find(ransomNote[i])==mp.end() || mp[ransomNote[i]]<=0)
                return false;
            else
                mp[ransomNote[i]]--;
        }
        return true;
    }
};