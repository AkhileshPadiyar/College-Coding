#include<bits/stdc++.h>
using namespace std;


bool comp(vector<int> a, vector<int> b) {
	if(a[1] < b[1]) return true;
	return false;
}

int solve(vector<int> &st, vector<int> &fn, set<int> &ans) {
	vector<vector<int>> arr;
	for(int i = 0; i < st.size(); i++) arr.push_back({st[i], fn[i], i});
	sort(arr.begin(), arr.end(), comp);
	
	int cnt = 0;
	int finishTime = INT_MIN;
	
	for(auto it: arr) {
		int sT = it[0], fT = it[1], taskNo = it[2] + 1;
		if(sT >= finishTime) {
			cnt++;
			finishTime = fT;
			ans.insert(taskNo);
		}
	}
	return cnt;
}

int	 main() {
	int n;
	cout << "\nEnter the no. of activities: ";
	cin >> n;
	vector<int> st(n, 0);
	cout << "\nEnter their start Times: ";
	for(int i = 0; i < n; i++) cin >> st[i];
	vector<int> fn(n,0);
	cout << "\nEnter their finish TImes: ";
	for(int i = 0; i < n; i++) cin >> fn[i];
	
	// TestCase 1:-
	//	vector<int> st = {1,3,0,5,3,5,8,8,2,12};
	//	vector<int> fn = {4,5,6,7,9,9,11,12,14,16};
	
	set<int> ans;
	int maxi = solve(st, fn, ans);
	
	cout << "\nThe maximum no. of activites he can perform is: " << maxi << "\n";
	cout << "\nList of selected activites: ";
	for(auto it: ans) cout << it << ", ";
	cout << "\n\n";
}
