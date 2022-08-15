/*
Author: Harshit Tiwari
Date: 31-07-2022
https://leetcode.com/problems/find-all-anagrams-in-a-string/
*/


class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(s.size() < p.size())
            return {};
        vector<int> ans;
        unordered_map<char, int> pmp; //to store freq of chars in 'p'
        unordered_map<char, int> smp; //to store freq of chars in a particular window in 's'
        
        //storing the frequencies of all the characters of 'p'
        for(auto& i: p)
            pmp[i]++;
        
        int i=0, j=0; //start and end index of the window in 's'
        while(j < s.size()){
            smp[s[j]]++; //increasing the frequency of the current character of 's'

            if((j - i + 1) > p.size()){ //if current window size becomes greater than no. of chars in 'p'
                //remove one element from the start of the window
                if(smp[s[i]] == 1)
                    smp.erase(s[i]);
                else
                    smp[s[i]] --;
                i++; //incrememt the start index, since one element was removed from the start
            }
            //if the two maps are equal then, that means the current window is an anagram of 'p', so store the start index of the window
            if(pmp == smp){
                ans.push_back(i);
            }
            j++;
        }
        return ans;
    }
};