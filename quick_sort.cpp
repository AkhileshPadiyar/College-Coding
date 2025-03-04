#include<bits/stdc++.h>
using namespace std;

// 23

void quickSort(vector<int> &arr, int low, int high, int &swaps, int &comp) {
	if(low >= high) return;
	
	int pivot = (low + high) / 2;
	
	// left sorting
	
	int flag = 2;
	
	while(flag > 0){
	
		flag = 0;
	
		for(int i = low; i < pivot; i++) {
			if(arr[i] > arr[pivot]) {
				swap(arr[i], arr[pivot]);
				pivot = i;
				flag++;
				swaps++;
				comp++;
			}
			else comp++;
		}
	
		// right sorting
	
		for(int i = high; i > pivot; i--) {
			if(arr[i] < arr[pivot]) {
				swap(arr[i], arr[pivot]);
				pivot = i;
				flag++;
				swaps++;
				comp++;
			}
			else comp++;
		}
	
	}
	
	quickSort(arr, low, pivot - 1,swaps, comp);
	quickSort(arr, pivot + 1, high, swaps, comp);
}

void printArr(vector<int> arr) {
	if(arr.size() == 0) cout << "\nEmpty Array";
	else {
		cout << "\nSorted Array Elements: ";
		for(int i = 0; i < arr.size(); i++) cout << arr[i] << " ";
	}
	cout << "\n";
}

int main() {
	int T;
	cout << "\nEnter the number of testcases: ";
	cin >> T;
	while(T--) {
		int n;
		cout << "\nEnter the size of array: ";
		cin >> n;
		vector<int> arr;
		int swaps = 0, comp = 0;
		cout << "\nEnter array elements: ";
		for(int i = 0; i < n; i++) {
			int ele;
			cin >> ele;
			arr.push_back(ele);
		}
		
		quickSort(arr, 0, n - 1, swaps, comp);
		printArr(arr);
		cout << "swaps: " << swaps << " comparisons: " << comp;
		cout << "\n";
	}
	return 0;
}
