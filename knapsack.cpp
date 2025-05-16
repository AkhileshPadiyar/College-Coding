#include<bits/stdc++.h>
using namespace std;

class Memoization{
	public:
	int n, N;
	vector<int> val;
	vector<vector<int>> dp;
	Memoization(int size, int target, vector<int> arr) {
		n = size;
		N = target;
		val = arr;
		dp.resize(n, vector<int> (N + 1, -1));
	}
	
	private:
		int f(int idx, int target, vector<int> &val, vector<vector<int>> &dp) {
			if(idx < 0) return 0;
	
			if(target == 0) return 1;
	
			if(dp[idx][target] != -1) return dp[idx][target];
			int notPick = f(idx - 1, target, val, dp);
			int Pick = 0;
			if(val[idx] <= target) Pick = f(idx, target - val[idx], val, dp);
	
			return dp[idx][target] = Pick + notPick;
		}
	
	public:
	int ans() {
		f(n - 1, N, val, dp);
		return dp[n - 1][N];
	}
};

class Tabulation{
	public:
	int n, N;
	vector<int> val;
	vector<vector<int>> dp;
	Tabulation(int size, int target, vector<int> arr) {
		n = size;
		N = target;
		val = arr;
		dp.resize(n + 1, vector<int> (N + 1, -1));
	}
	
	int ans() {
		for(int target = 0; target <= N; target++) dp[0][target] = 0;
	
		for(int i = 0; i <= n; i++)	dp[i][0] = 1;
	
		for(int idx = 1; idx <= n; idx++) {
			for(int target = 0; target <= N; target++) {
				int notPick = dp[idx - 1][target];
				int Pick = 0;
				if(val[idx - 1] <= target) Pick = dp[idx][target - val[idx - 1]];
				dp[idx][target] = Pick + notPick;
			}
		}
		
		return dp[n][N];
	}
	
};

int main() {
	int n;
	cout << "Enter the number of coins: ";
	cin >> n;
	vector<int> val(n, 0);
	cout << "Enter value of each coin: ";
	for(int i = 0; i < n; i++) cin >> val[i];
	
	int N;
	cout << "Enter the target value: ";
	cin >> N;
	
	// Memoization:-
	
	Memoization m(n, N, val);
	
	cout << "Memoization method: " << m.ans() << endl;
	
	
	// Tabulation Code:- 
	
	Tabulation t(n,N,val);
	
	cout << "Tabulation method: " << t.ans() << endl;
	
}
