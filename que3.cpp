#include<bits/stdc++.h>
using namespace std;

bool MajorityElement(vector<int> arr) {
	int n = arr.size();
	int candidate = -1, count = 0;
	for(int i = 0; i < n; i++) {
		if(count == 0) {
			candidate = arr[i];
			count++;
		}
		else if(arr[i] == candidate) count++;
		else count--;
	}
	
	count = 0;
	for(auto it: arr) {
		if(it == candidate)	count++;
	}
	
	if(count > n/2) return true;
	return false;
}

int main() {
	
	int n;
	cout << "\nEnter the size of an array: ";
	cin >> n;
	
	vector<int> arr(n,0);
	cout << "\nEnter array elements: ";
	for(int i = 0; i < n; i++) cin >> arr[i];
	
	//sort(arr.begin(), arr.end());
	
	if(MajorityElement(arr)) cout << "\nYes\n";
	else cout << "\nNo\n";
	
	int median = 0;
	int idx = (n + 1) / 2;
	if(n % 2 != 0){
		median = arr[idx - 1];
	}
	else {
		median = (arr[idx] + arr[idx - 1]) / 2; 
	}
	
	cout << "Median is : " << median << "\n\n";
	
	
}
