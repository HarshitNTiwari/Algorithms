/*
Author: Harshit Tiwari
Date: 14-12-2022
https://practice.geeksforgeeks.org/problems/quick-sort/1
*/

class Solution
{
public:
	//Function to sort an array using quick sort algorithm.
	void quickSort(int arr[], int low, int high)
	{
		if (low < high) {
			int p = partition(arr, low, high);
			quickSort(arr, low, p - 1);
			quickSort(arr, p + 1, high);
		}
	}

public:
	// Function to partition an array around a pivot
	int partition (int arr[], int low, int high)
	{
		int pivot = high;
		int i = low - 1;

		int j = low;
		while (j < high) {
			if (arr[j] < arr[pivot]) {
				i++;
				swap(arr[j], arr[i]);
			}
			j++;
		}

		swap(arr[pivot], arr[i + 1]);
		return i + 1;  // returning the correct position of the element selected as the pivot
	}
};