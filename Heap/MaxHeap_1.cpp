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
	void insert(vector<int>& input);
	void heapify(int i);
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

void MaxHeap::heapify(int i) {
	int largerChild = i;
	if (arr[leftChildIndex(i)] > arr[largerChild])
		largerChild = leftChildIndex(i);
	if (arr[rightChildIndex(i)] > arr[largerChild])
		largerChild = rightChildIndex(i);

	if (largerChild != i) {
		swap(arr[i], arr[largerChild]);
		heapify(largerChild);
	}
	return;
}

void MaxHeap::insert(vector<int>& input) {
	if (input.size() > capacity) {
		cout << "Error: Heap Overflow!" << endl;
		return;
	}
	for (int i = 0; i < input.size(); i++) {
		arr[size] = input[i];
		size++;
	}

	int lastNonLeaf = (size / 2) - 1;

	for (int i = lastNonLeaf; i >= 0; i--) {
		heapify(i);
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
	heap.insert(input);

	cout << "The constructed heap is: ";
	for (int i = 0; i < N; i++) {
		cout << heap.arr[i] << ", ";
	}
	return 0;
}