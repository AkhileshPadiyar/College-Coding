#include<bits/stdc++.h>
using namespace std;

bool f(int idx, int target, vector<int> &arr, vector<vector<int>> &dp) {
	if(idx == 0) {
		if(arr[idx] == target) return true;
		return false;
	}
	if(target == 0) return true;
	if(dp[idx][target] != -1) return dp[idx][target];
	bool notPick = f(idx - 1, target, arr, dp);
	bool pick = false;
	if(arr[idx] <= target) pick = f(idx - 1, target - arr[idx], arr, dp);
	
	return dp[idx][target] =  pick | notPick;
}

bool tab(int n, int s, vector<int> &arr, vector<vector<bool>> &dp) {
	for(int i = 0; i <= s; i++) dp[0][i] = false;
	for(int i = 0; i <= n; i++) dp[i][0] = true;
	
	for(int idx = 1; idx <= n; idx++) {
		for(int target = 1; target <= s; target++) {
			bool notPick = dp[idx - 1][target];
			bool pick = false;
			if(arr[idx - 1] <= target) pick = dp[idx - 1][target - arr[idx - 1]];
			dp[idx][target] =  pick | notPick;
		}
	}
	return dp[n][s];
}

int main() {
	int n;
	cin >> n;
	
	vector<int> arr(n, 0);
	for(int i = 0; i < n; i++) cin >> arr[i];
	
	int sum = 0;
	for(int i = 0; i < n; i++) sum += arr[i];
	
	if(sum % 2 != 0) {
		cout << "No" << endl;
	}
	else {
		vector<vector<bool>> dp(n + 1 , vector<bool> (sum/ 2 + 1, false));
		bool ans = tab(n, sum / 2, arr, dp);
		if(ans) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
}
