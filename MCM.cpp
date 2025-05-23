#include<bits/stdc++.h>
using namespace std;

// memoization

int MCM(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &dp) {
	if(i == j) return 0;
	if(dp[i][j] != -1) return dp[i][j];
	int mini = INT_MAX;
	for(int k = i; k < j; k++) {
		int cost = matrix[i][0] * matrix[j][1] * matrix[k][1] + MCM(i, k, matrix, dp) + MCM(k + 1, j, matrix, dp);
		mini = min(cost, mini);
	}
	return dp[i][j] = mini;
} 

int tab(vector<vector<int>> &matrix, vector<vector<int>> &dp) {
	int n = matrix.size();
	for(int i = n - 1; i >= 0; i--) {
		for(int j = i + 1; j < n; j++) {
			int mini = INT_MAX;
			for(int k = i; k < j; k++) {
				int cost = matrix[i][0] * matrix[j][1] * matrix[k][1] +	dp[i][k] + dp[k + 1][j];
				mini = min(cost, mini);
			}
			dp[i][j] = mini;
		}
	}
	return dp[0][n - 1];
}

int main() {
	int n;
	cin >> n;
	vector<vector<int>> arr(n, vector<int> (2,0));
	
	vector<vector<int>> dp(n, vector<int> (n, 0));
	
	for(int i = 0; i < n; i++) {
		cin >> arr[i][0] >> arr[i][1];
	}
	
	//int ans = MCM(0, n - 1, arr, dp);
	
	int ans = tab(arr, dp);
	
	cout << ans << endl;
}
