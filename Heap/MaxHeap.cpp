#include<iostream>
#include <vector>

using namespace std;

static int capacity = 100;

class MaxHeap {
public:
	vector<int> arr;
	MaxHeap(int capacity) {
		arr = vector<int>(capacity, -1);
	}
	int size = 0;
	int leftChildIndex(int rootIndex);
	int rightChildIndex(int rootIndex);
	int parentIndex(int rootIndex);
	void insert(int val);
};

int MaxHeap::leftChildIndex(int rootIndex) {
	return (2 * rootIndex + 1);
}

int MaxHeap::rightChildIndex(int rootIndex) {
	return (2 * rootIndex + 2);
}

int MaxHeap::parentIndex(int rootIndex) {
	return (rootIndex - 1) / 2;
}

// Heapify operation : log(n)
void MaxHeap::insert(int val) {
	if (size > capacity)
		return;
	arr[size] = val;
	size++;
	int i = size - 1;
	while (i != 0 && arr[parentIndex(i)] < arr[i]) {
		swap(arr[parentIndex(i)], arr[i]);
		i = parentIndex(i);
	}
	return;
}

int main() {
	vector<int> input;
	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		int k; cin >> k;
		input.push_back(k);
	}
	MaxHeap heap(capacity);
	for (int i = 0; i < N; i++) {
		heap.insert(input[i]);
	}

	cout << "The constructed heap is: ";
	for (int i = 0; i < N; i++) {
		cout << heap.arr[i] << ", ";
	}
	return 0;
}