#include<iostream>
using namespace std;

void Heapify(int arr[], int idx, int n) {
	int lchild = 2 * idx + 1;
	int rchild = 2 * idx + 2;
	int largest = idx;
	if(lchild < n && arr[largest] < arr[lchild]) largest = lchild;
	if(rchild < n && arr[largest] < arr[rchild]) largest = rchild;
	if(idx != largest) {
		swap(arr[idx], arr[largest]);
		Heapify(arr, largest, n);
	}
}

void MaxHeap(int arr[], int n) {
	for(int i = n/2 - 1; i >= 0; i--) {
		Heapify(arr, i, n);
	}
}

void HeapSort(int arr[], int n) {
	for(int i = 0; i < n; i++) {
		MaxHeap(arr, n - i);
		swap(arr[0], arr[n - i - 1]);
	}
}

void printArr(int arr[], int n) {
	if(n == 0) cout << "Empty Arr" << endl;
	else {
		cout << "Array Elemets: ";
		for(int i = 0; i < n; i++) cout << arr[i] << ", ";
		cout << endl;
	}
}

int main() {
	int n;
	cout << "Enter the size of arr: ";
	cin >> n;
	cout << "Enter array elements: ";
	int arr[n];
	for(int i = 0; i < n; i++) cin >> arr[i];
	
	HeapSort(arr, n);
	printArr(arr, n);
}
