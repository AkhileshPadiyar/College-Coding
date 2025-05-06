#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cout << "Enter the number of files: ";
	cin >> n;
	vector<int> s(n, 0);
	cout << "Enter the size of files: " << endl;
	for(int i = 0; i < n; i++) cin >> s[i];
	
	priority_queue<int, vector<int>, greater<int>> pq;
	for(int i = 0; i < n; i++) pq.push(s[i]);
	
	int ans = 0;
	while(pq.size() > 1) {
		int v1 = pq.top();
		pq.pop();
		int v2 = pq.top();
		pq.pop();
		int size = v1 + v2;
		ans += size;
		pq.push(size);
	}
	cout << "Minimum computional cost : " << ans << endl;
}
