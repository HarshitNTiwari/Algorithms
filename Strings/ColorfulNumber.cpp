/*
Author: Harshit Tiwari
Date: 26-12-2022
https://www.interviewbit.com/problems/colorful-number/
*/

int Solution::colorful(int A) {
	unordered_set<int> uset;
	vector<int> vec;

	while (A) {
		int last = A % 10;
		A /= 10;
		for (auto& i : vec)
			i *= last;
		vec.push_back(last);
		for (auto& i : vec) {
			if (uset.find(i) != uset.end())
				return 0;
			uset.insert(i);
		}
	}
	return 1;
}
