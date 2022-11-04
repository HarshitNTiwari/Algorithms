#include <iostream>
#include <vector>

using namespace std;

class MinHeap {
	vector<int> arr;
	int size = 0;
	int leftChild(int i);
	int rightChild(int i);
	int parent(int i);
	void insert(int x);
};

int MinHeap::leftChild(int i) {
	return 2 * i + 1;
}

int MinHeap::rightChild(int i) {
	return 2 * i + 2;
}

int MinHeap::parent(int i) {
	return (i - 1) / 2;
}

void MinHeap::insert(int x) {
	size++;
	arr.push_back(x);
	int i = size - 1;
	while ( i != 0 && arr[parent(i)] > arr[i]) {
		swap(arr[i], arr[parent(i)]);
		i = parent(i);
	}
}

