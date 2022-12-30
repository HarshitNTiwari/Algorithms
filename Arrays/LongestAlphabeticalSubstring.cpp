/*
Author: Harshit Tiwari
Date: 27-12-2022
https://leetcode.com/problems/length-of-the-longest-alphabetical-continuous-substring/
*/

class Solution {
public:
	int longestContinuousSubstring(string s) {
		int i = 0; int j = 1;
		int ans = 0; int currLen = 1;
		while (j < s.size()) {
			if (s[i] == s[j] - 1) {
				currLen++;
			}
			else {
				ans = max(ans, currLen);
				currLen = 1;
			}
			i++;
			j++;
		}
		ans = max(ans, currLen);
		return ans;
	}
};