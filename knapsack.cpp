#include<bits/stdc++.h>
using namespace std;

float knapsack(int n, vector<int> weights, vector<int> values, int maxCap, vector<pair<int,int>> &itemWeight) {
	priority_queue<pair<float,pair<int,int>>> pq;
	for(int i = 0; i < n; i++) {
		float ratio = values[i] * 1.0 / weights[i];
		pq.push({ratio, {i + 1, weights[i]}});
	}
	
	float ans = 0;
	while(!pq.empty() && maxCap != 0) {
		auto it = pq.top();
		pq.pop();
		float r = it.first;
		int item = it.second.first;
		int wt = it.second.second;
		if(wt > maxCap) {
			ans += maxCap * r;
			itemWeight.push_back({item, maxCap});
			maxCap = 0;
		}
		else {
			ans += wt * r;
			maxCap -= wt;
			itemWeight.push_back({item, wt});
		}
	}
	return ans;
}

int main() {
	int n;
	cout << "Enter the number of items: ";
	cin >> n;
	vector<int> weights(n, 0), value(n, 0);
	cout << "Enter weights " << n << " size: ";
	for(int i = 0; i < n; i++) cin >> weights[i];
	cout << "Enter their values " << n << " size: ";
	for(int i = 0; i < n; i++) cin >> value[i];
	
	int maxCap;
	cout << "Maximum capacity of bag : ";
	cin >> maxCap;
	
	vector<pair<int,int>> itemWeight;
	
	float minWt = knapsack(n, weights, value, maxCap, itemWeight);
	
	cout << "Minimum weights is : " << minWt << endl;
	cout << "item--weight" << endl;
	for(int i = 0; i < itemWeight.size(); i++) cout << itemWeight[i].first << "--" << itemWeight[i].second << endl;
	return 0;
}
