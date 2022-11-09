/*
Author: Harshit Tiwari
Date: 06-11-2022
https://leetcode.com/problems/reverse-words-in-a-string/
*/

// T.C. : O(n) , S.C. : O(n)
// A better solution is in Strings/ReverseWords_2.cpp and even better in Strings/ReverseWords_3.cpp

class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        string temp; char prev = ' ';
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ' ') {
                temp.push_back(s[i]);
                if (i == s.size() - 1)
                    st.push(temp);
            }
            else if (prev != ' ' && s[i] == ' ') {
                st.push(temp);
                st.push(" ");
                temp = "";
            }
            prev = s[i];
        }

        while (!st.empty() && st.top() == " ") {
            st.pop();
        }

        string ans;
        while (!st.empty()) {
            ans += (st.top());
            st.pop();
        }

        return ans;
    }
};