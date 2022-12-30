/*
Author: Harshit Tiwari
Date: 14-12-2022
https://leetcode.com/problems/kth-largest-element-in-an-array/
*/

// Solution using Quickselect Algorithm

class Solution {
public:
	// Function to partition an array around a pivot
	int partition(vector<int>& nums, int low, int high) {
		int pivot = high;
		int i = low - 1;
		int j = low;

		while (j < high) {
			if (nums[j] >= nums[pivot]) {
				i++;
				swap(nums[i], nums[j]);
			}
			j++;
		}
		swap(nums[pivot], nums[i + 1]);
		return i + 1; // returning the correct position of the element selected as the pivot
	}

	int kthLargest(vector<int>& nums, int low, int high, int k) {
		int p = partition(nums, low, high);

		if (k - 1 == p)
			return nums[p];
		if (k - 1 < p)
			return kthLargest(nums, low, p - 1, k);
		else
			return kthLargest(nums, p + 1, high, k);
	}

	int findKthLargest(vector<int>& nums, int k) {
		return kthLargest(nums, 0, nums.size() - 1, k);
	}
};