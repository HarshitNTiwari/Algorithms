/*
Author: Harshit Tiwari
Date: 03-11-2022
https://leetcode.com/problems/remove-k-digits/
*/

class Solution {
public:
	string removeKdigits(string num, int k) {
		if (k == num.size())  //if k ==num.size(), then all the digits can be removed and ans  "0"
			return "0";
		stack<char> st;

		for (int i = 0; i < num.size(); i++) {
			char f = num[i];
			while (k > 0 && !st.empty() && st.top() > f) {
				k--;
				st.pop(); //removing an element from stack means removing a digit from num
			}
			st.push(f);
		}

		while (k) {    //if k is still not zero, then remove more elements from the stack
			st.pop();
			k--;
		}

		// now stack has only those digits which will be in the answer (plus leading zeroes, if any)
		string ans;
		while (!st.empty()) {
			ans.push_back(st.top());
			st.pop();
		}

		reverse(ans.begin(), ans.end());

		while (ans.size() > 1 && ans[0] == '0') { //remove any leading zeroes
			ans = ans.substr(1);
		}
		return ans;
	}
};