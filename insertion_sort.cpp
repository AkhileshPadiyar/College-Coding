 #include<iostream>
 #include<bits/stdc++.h>
 
 using namespace std;
 
 int insertion_sort(vector<int> &arr, int &shift) {
 	int n = arr.size();
 	int no_of_swaps = 0;
 	for(int i = 1; i < n; i++) {
 		int j = i;
 		while(j > 0 && arr[j] < arr[j - 1]) {
 			swap(arr[j], arr[j - 1]);
 			j--;
 			no_of_swaps++;
 			shift++;
 		}
 		if(j >= 0) no_of_swaps++;
 	}
 	return no_of_swaps;
 }
 
 void printArr(vector<int> arr) {
 	int n = arr.size();
 	if(n == 0) cout << "Empty array" << endl;
 	else {
 		for(int i = 0; i < n; i++)
 			cout << arr[i] << ", ";
 		cout << endl;
 	}
 }
 
 int main() {
 	int T;
 	cout << endl << "Enter the number of testcases: ";
 	cin >> T;
 	cout << endl;
 	while(T--){
 		int n, shift = 0;
 		cout << "Enter the size of arr: ";
 		cin >> n;
 		cout << endl;
 		cout << "Enter arr elements: ";
 		vector<int> arr;
 		for(int i = 0; i < n; i++) {
 			int ele;
 			cin >> ele;
 			arr.push_back(ele); 		
 		}
 		cout << endl << "Before sorting : ";
 		printArr(arr);
 		cout << endl;
 		cout << "After sorting: ";
 		int no_of_swaps = insertion_sort(arr,shift);
 		printArr(arr);
 		cout << endl;
 		cout << "Number of shifts : " << shift << endl;
 		cout << endl;
 		cout << "Number of comparisons performed: " << no_of_swaps << endl;
 		cout << endl;
 		
 	} 
 
 	return 0;
 }
