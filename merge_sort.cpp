#include<iostream> 

#include<bits/stdc++.h>

using namespace std;

void merging(int arr[], int low, int mid, int mid2, int high) {
	int newArr[high - low + 1];
	int ptr = 0;
	int ptr1 = low;
	
	while(low <= mid && mid2 <= high) {
		if(arr[low] < arr[mid2]) newArr[ptr++] = arr[low++];
		else newArr[ptr++] = arr[mid2++];
	}
	
	while(low <= mid) {
		newArr[ptr++] = arr[low++];
	}
	
	while(mid2 <= high) {
		newArr[ptr++] = arr[mid2++];
	}
	
	for(int i = 0; i < ptr; i++)
		arr[ptr1++] = newArr[i]; 
}

void mergeSort(int arr[], int low, int high) {
	if(low == high) return;
	
	int mid = (low + high) / 2;
	mergeSort(arr, low, mid);
	mergeSort(arr, mid + 1, high);
	merging(arr, low, mid, mid + 1, high);
}

void printArr(int arr[] , int n) {
	if(n <= 0) cout << "\nEmpty array";
	
	cout << "\nAfter Sorting: ";
	
	for(int i = 0; i < n; i++)
		cout << arr[i] << ", ";
		
	cout << "\n";
}


int main() {
	int T;
	cout << "\n" << "Enter the number of testcases: ";
	cin >> T;
	while(T--) {
		int n;
		cout << "\n Enter the size of array: " ;
		cin >> n;
		int arr[n];
		cout << "\n Enter array elements: ";
		for(int  i = 0; i < n; i++) {
			int ele;
			cin >> ele;
			arr[i] = ele;
		}
		mergeSort(arr, 0, n - 1);
		printArr(arr, n);
	}
	return 0;
}
