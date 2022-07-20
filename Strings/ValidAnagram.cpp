/*
Author: Harshit Tiwari
Date: 19-07-2022
https://leetcode.com/problems/valid-anagram/
*/


class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())
            return false;
        
        unordered_map<int, int> smap; //map to store freq of letters in s
        for(auto& i: s)
            smap[i]++;
        
        for(int i=0; i<t.size(); i++){
            if(smap.find(t[i])==smap.end())  //if a particluar letter in t not found in s
                return false;
            else if(smap.find(t[i])!=smap.end()){
                if(smap[t[i]]==0)    //if letter was found but is repeated
                    return false;
                else
                    smap[t[i]]--;   //reducing the freq by 1
            }
        }
        return true;
    }
};