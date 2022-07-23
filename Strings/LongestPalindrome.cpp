/*
Author: Harshit Tiwari
Date: 21-06-2022
https://leetcode.com/problems/longest-palindrome/
*/


class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> freq;
        
        for(auto& i: s)
            freq[i]++;
        
        int ans = 0;  int odd = 0;
        for(int i=0; i<s.size(); i++){
            if(freq[s[i]] != 0){
                if(freq[s[i]] % 2 == 0)  //if the freq of a char is even 
                    ans += freq[s[i]];  // all the occurences of that char can be counted
                else{
                    ans += freq[s[i]] - 1;
                    odd ++;
                }
                freq[s[i]] = 0;
            }
        }
        
        return odd != 0 ? ans + 1 : ans ;
    }
};