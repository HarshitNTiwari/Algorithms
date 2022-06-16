/*
Author: Harshit Tiwari
Date: 15-06-2022
https://leetcode.com/problems/longest-nice-substring/
*/

class Solution {
public:
    // Function to check if a string s is nice
    bool checkNice(string s) {
        vector<int> lower(26, -1);
        vector<int> upper(26, -1);
        for (int i = 0; i < s.size(); i++) {
            if (islower(s[i])) {
                int j = s[i] - 'a';
                lower[j] = j;
            }
            else if (isupper(s[i])) {
                int j = s[i] - 'A';
                upper[j] = j;
            }
        }
        for (int i = 0; i < 26; i++)
            if (lower[i] != upper[i])
                return false;
        return true;
    }
    // Here simply applying brute force to check if each of the substrings are nice
    string longestNiceSubstring(string s) {
        string ans;
        for (int i = 0; i < s.size() - 1; i++) {
            string sub;
            char c = s[i];
            sub.push_back(c);
            for (int j = i + 1; j < s.size(); j++) {
                char c = s[j];
                sub.push_back(c);
                if (checkNice(sub) && sub.size() > ans.size())
                    ans = sub;
            }
        }
        return ans;
    }
};