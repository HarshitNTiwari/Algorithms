/*
Author: Harshit Tiwari
Date: 06-11-2022
https://leetcode.com/problems/reverse-words-in-a-string/
*/

// T.C. : O(n) , S.C. : O(1)


class Solution {
public:
	string reverseWords(string s) {
		string ans; int i = 0, j = 0;
		while (i < s.size()) {
			while (i < s.size() && s[i] == ' ') //ignore the spaces
				i++;
			if (i < s.size() && j > 0) { //add a space after a word
				s[j] = ' '; j++;
			}
			int start = j;
			while (i < s.size() && s[i] != ' ') {
				s[j] = s[i];
				i++; j++;
			}
			reverse(s.begin() + start, s.begin() + j); //reverse that particular word
		}
		s.resize(j);
		reverse(s.begin(), s.end());  //reversing the whole string

		return s;
	}
};