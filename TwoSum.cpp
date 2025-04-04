#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class MaxHeap{
public:
	vector<int> arr;
	MaxHeap(vector<int> a) {
		arr = a;
		for(int idx = arr.size() - 1; idx > 0; idx--) {
			int i = idx;
			while(i > 0) {
				int parent = (i - 1) / 2;
				if(parent >= 0 && arr[i] > arr[parent]) {
					swap(arr[i], arr[parent]);
					i = parent;
				}
				else break;
			}
		}
	}
	
	void insertVal(int val) {
		arr.push_back(val);
		int i = arr.size() - 1;
		while(i > 0) {
			int parent = (i - 1) / 2;
			if(parent >= 0 && arr[i] > arr[parent]) {
				swap(arr[i], arr[parent]);
				i = parent;
			}
			else break;
		}
	}
	
	void deleteVal() {
		if(arr.size() == 0) 	printf("Already empty");
		else {
			swap(arr[0], arr[arr.size() - 1]);
			arr.pop_back();
			int idx = 0;
			while(true) {
				int largest = idx;
				int leftchild = 2 * idx + 1;
				int rightchild = 2 * idx + 2;
				if(leftchild < arr.size() && arr[leftchild] > arr[largest]) largest = leftchild;
				if(rightchild < arr.size() && arr[rightchild] > arr[largest]) largest = rightchild;
				if(largest == idx) break;
				swap(arr[largest], arr[idx]);
				idx = largest;
			}
		}
	}
	int top() {
		return arr[0];
	}
};

void printArr(vector<int> arr) {
	if(arr.size() == 0) {
		cout << "Empty arr" << endl;
		return;
	}
	for(int i = 0; i < arr.size(); i++) cout << arr[i] << ", ";
	cout << endl;
}

int main() {
	vector<int> arr = {11, 3, 21, 2, 35, 12, 9};
	auto heap = MaxHeap(arr);
	for(int i = 0; i < arr.size(); i++) {
		arr[i] = heap.top();
		heap.deleteVal();
	}
	
	printArr(arr);
	
	int key;
	cout << "Enter element: ";
	cin >> key;
	
	int ptr1 = 0, ptr2 = arr.size() - 1;
	while(ptr1 < ptr2) {
		int s = arr[ptr1] + arr[ptr2];
		if(s > key) ptr1++;
		else if(s < key) ptr2--;
		else {
			cout << arr[ptr1] << " + " << arr[ptr2] << " = " << key << endl;
			return 0;
		}
	}
	cout << "Not found" << endl;
	
}
