#include<bits/stdc++.h>
using namespace std;

int f(int idx, int target, vector<int> &arr, vector<vector<int>> &dp) {
	if(idx == 0) return 0;
	if(target == 0) return 1;
	
	if(dp[idx][target] != -1) return dp[idx][target];
	
	int notPick = 0 + f(idx - 1, target, arr, dp);
	int pick = 0;
	if(arr[idx - 1] <= target)	pick = f(idx, target - arr[idx - 1], arr, dp);
	
	return dp[idx][target] =  notPick + pick;
}

int tab(vector<int> arr, vector<vector<int>> &dp, int sum) {
	
	int n = arr.size();
	for(int i = 0; i <= sum; i++) dp[0][i] = 0;
	for(int i = 0; i <= n; i++) dp[i][0] = 1;
	
	for(int idx = 1; idx <= n; idx++) {
		for(int target = 1; target <= sum; target++) {
			int notPick = 0 + dp[idx - 1][target];
			int pick = 0;
			if(arr[idx - 1] <= target)	pick = dp[idx][target - arr[idx - 1]];
			dp[idx][target] =  notPick + pick;
		}
	}
	return dp[n][sum];
}

int main() {
	int n;
	cin >> n;
	vector<int> arr(n,0);
	for(int i = 0; i < n; i++) cin >> arr[i];
	
	int sum;
	cin >> sum;
	
	vector<vector<int>> dp(n + 1, vector<int> (sum + 1, 0));
	int ans = tab(arr, dp, sum);
	cout << ans << endl;
}
