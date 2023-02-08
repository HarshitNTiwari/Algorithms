/*
Author: Harshit Tiwari
Date: 05-02-2023
https://leetcode.com/problems/count-vowel-strings-in-ranges/
*/

class Solution {
public:
	bool isVowel(string& s) {
		int n = s.size();
		if (s[0] != 'a' && s[0] != 'e' && s[0] != 'i' && s[0] != 'u' && s[0] != 'o')
			return false;
		if (s[n - 1] != 'a' && s[n - 1] != 'e' && s[n - 1] != 'i' && s[n - 1] != 'u' && s[n - 1] != 'o')
			return false;
		return true;
	}
	vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {

		vector<int> nums;
		for (string s : words) {
			if (isVowel(s))
				nums.push_back(1);
			else
				nums.push_back(0);
		}
		for (int i : nums) {
			cout << i << " ";
		}
		cout << endl;
		vector<int> num = nums;
		for (int i = 1; i < num.size(); i++) {
			num[i] = num[i] + num[i - 1];
		}
		for (int i : num) {
			cout << i << " ";
		}
		vector<int> ans;
		for (vector<int> i : queries) {
			if (i[0] == 0)
				ans.push_back(num[i[1]]);
			else if (nums[i[0]] == 0) {
				ans.push_back(num[i[1]] - num[i[0]]);
			}
			else if (nums[i[0]] == 1) {
				ans.push_back(num[i[1]] - num[i[0]] + 1);
			}
		}
		return ans;
	}
};