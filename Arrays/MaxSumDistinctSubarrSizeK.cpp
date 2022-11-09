/*
Author: Harshit Tiwari
Date: 06-11-2022
https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/
*/

class Solution {
public:
	long long maximumSubarraySum(vector<int>& nums, int k) {
		unordered_map<int, int> freq;
		int i = 0, j = 0; long long sum = 0, ans  = 0;
		while (j < nums.size()) {
			if (freq.find(nums[j]) == freq.end()) {
				sum += nums[j];
				freq[nums[j]]++;
			}
			else {
				while (freq[nums[j]] > 0) {
					sum -= nums[i];
					freq[nums[i]]--;
					i++;
				}
				sum += nums[j];
				freq[nums[j]]++;
			}
			while (j - i + 1 > k) {
				sum -= nums[i];
				freq[nums[i]]--;
				i++;
			}
			if (j - i + 1 == k)
				ans = max(ans, sum);
			j++;
		}
		return ans;
	}
};