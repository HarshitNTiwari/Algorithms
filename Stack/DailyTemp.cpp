/*
Author: Harshit Tiwari
Date: 01-07-2022
https://leetcode.com/problems/daily-temperatures/
*/


class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans;
        stack<int> st; 
        unordered_map<int, int> index;
        
        for(int i=temperatures.size()-1; i>=0; i--){
            while(!st.empty() && st.top()<=temperatures[i]){
                st.pop();
            }
            if(st.empty()){
                ans.push_back(0);
            }
            else{
                ans.push_back(index[st.top()] - i);
            }
            st.push(temperatures[i]);
            index[temperatures[i]] = i;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};