/*
Author: Harshit Tiwari
Date: 26-06-2022
https://leetcode.com/problems/evaluate-reverse-polish-notation/
*/


class Solution {
    bool isNumber(string& str){
        for(char c: str){
            if(str.size()>1 && c=='-')
                return true;
            if(!isdigit(c))
                return false;
        }
        return true;
    }
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(int i=0; i<tokens.size(); i++){
            if(isNumber(tokens[i])){
                int n = stoi(tokens[i]);
                st.push(n);
            }
            else{
                int num2 = st.top();
                st.pop();
                int num1 = st.top();
                st.pop();
                if(tokens[i]=="+")
                    st.push(num1+num2);
                else if(tokens[i]=="-")
                    st.push(num1-num2);
                else if(tokens[i]=="*")
                    st.push(num1*num2);
                else if(tokens[i]=="/")
                    st.push(num1/num2);
            }
        }
        return st.top();
    }
};