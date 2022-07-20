/*
Author: Harshit Tiwari
Date: 20-07-2022
https://leetcode.com/problems/backspace-string-compare/
*/


class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> sstack;
        stack<char> tstack;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='#' && !sstack.empty())
                sstack.pop();
            else if(s[i]!='#')
                sstack.push(s[i]);
        }
        for(int i=0; i<t.size(); i++){
            if(t[i]=='#' && !tstack.empty())
                tstack.pop();
            else if(t[i]!='#')
                tstack.push(t[i]);
        }
        string s_new;
        while(!sstack.empty()){
            s_new.push_back(sstack.top());
            sstack.pop();
        }
        
        string t_new;
        while(!tstack.empty()){
            t_new.push_back(tstack.top());
            tstack.pop();
        }
        
        return s_new == t_new ? true : false;
    }
};