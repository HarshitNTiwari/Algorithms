/*
Author: Harshit Tiwari
Date: 06-11-2022
https://leetcode.com/problems/reverse-words-in-a-string/
*/

// T.C. : O(n) , S.C. : O(1)
// A better solution is in Strings/ReverseWords_3.cpp
// An alternate solution using stack is in Stack/ReverseWords_1.cpp

class Solution {
public:
	string reverseWords(string s) {
		string ans;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == ' ') //On encountering space, do nothing and continue
				continue;
			string temp;
			while (i < s.size() && s[i] != ' ') { //collect the characters of a word till next space is not encountered
				temp.push_back(s[i]);
				i++;
			}
			if (!ans.size())
				ans += temp; //this will be the last word in the ans string
			else
				ans = temp + " " + ans; //adding newer words at the beginning of the ans, so as to reverse the original string
		}

		return ans;
	}
};