/*
Author: Harshit Tiwari
Date: 15-08-2022
https://leetcode.com/problems/letter-combinations-of-a-phone-number/
*/


class Solution {
    void solve(string digits, int index, string currStr, unordered_map<char, string>& mp, vector<string>& ans){
        if(index >= digits.size()) //i.e. current string is now complete as all the digits have been traversed
            ans.push_back(currStr);
        string t = mp[digits[index]]; 
        // traversing the string corresponding to that digit
        for(int j=0; j<t.size(); j++){
            currStr.push_back(t[j]); //add this char to the current string 
            solve(digits, index+1, currStr, mp, ans);
            currStr.pop_back(); //Backtrack; that is remove the the last added char from the current string and then move to the next char
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits == "")
            return ans;
        unordered_map<char, string> mp; //map to store the strings corresponding to each of the digits
        mp['2'] = "abc"; mp['3'] = "def"; mp['4'] = "ghi"; mp['5'] = "jkl"; 
        mp['6'] = "mno"; mp['7'] = "pqrs"; mp['8'] = "tuv"; mp['9'] = "wxyz";
        
        solve(digits, 0, "", mp, ans);
        return ans;
    }
};