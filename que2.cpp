#include<bits/stdc++.h>
using namespace std;

bool comp(vector<int> a , vector<int> b) {
	if(a[0] < b[0]) return true;
	return false;
}
int solve(vector<int> &tt, vector<int> &fn, set<int> &st) {
	int n = tt.size();
	vector<vector<int>> arr;
	for(int i = 0; i < n; i++) arr.push_back({tt[i], fn[i], i});
	
	sort(arr.begin(), arr.end(), comp);
	
	int cnt = 0, totalTime = 0;
	for(auto it: arr) {
		int tm = it[0], ft = it[1], taskNo = it[2] + 1;
		if(ft >= totalTime + tm) {
			totalTime += tm;
			 cnt++;
			 st.insert(taskNo);
		}
	}
	return cnt;
}

int main() {
	int n;
	cout << "\nEnter the number of Tasks: ";
	cin >> n;
	
	vector<int> tt(n,0);
	cout << "\nEnter time taken by each Task: ";
	for(int i = 0 ; i< n; i++) cin >> tt[i];
	
	vector<int> fn(n,0);
	cout << "\nEnter the deadline of each Task: ";
	for(int i = 0; i < n; i++) cin >> fn[i];
	
	// TestCase 1:-
	//vector<int> tt = {2,1,3,2,2,2,1};
	//vector<int> fn = {2,3,8,6,2,5,3};
	
	set<int> st;
	int ans = solve(tt, fn, st);
	
	cout << "\nMax number of tasks: " << ans << endl;
	
	cout << "\nSelected taks numbers: ";
	for(auto it: st) cout << it << ", ";
	cout << "\n\n";
	
	
	
}
