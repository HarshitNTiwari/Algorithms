/*
Author: Harshit Tiwari
Date: 07-01-2023
https://leetcode.com/problems/candy/
*/

class Solution {
public:
	int candy(vector<int>& ratings) {
		vector<int> candies(ratings.size(), 1);
		for (int i = 1; i < ratings.size(); i++) {
			if (ratings[i] > ratings[i - 1])
				candies[i] = candies[i - 1] + 1;
			else if (ratings[i] < ratings[i - 1])
				candies[i - 1] = candies[i] + 1;
		}

		for (int i = ratings.size() - 1; i > 0; i--) {
			if (ratings[i] > ratings[i - 1]) {
				if (candies[i] <= candies[i - 1])
					candies[i] = candies[i - 1] + 1;
			}
			else if (ratings[i] < ratings[i - 1]) {
				if (candies[i] >= candies[i - 1])
					candies[i - 1] = candies[i] + 1;
			}
		}
		int sum = 0;
		for (auto i : candies)
			sum += i;

		return sum;
	}
};