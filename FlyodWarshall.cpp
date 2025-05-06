#include<bits/stdc++.h>
using namespace std;

void flyodWarshall(int V, vector<pair<int,int>> adj[], vector<vector<int>> &dist) {
    for(int i = 0; i < V; i++) dist[i][i] = 0;
    
    for(int i = 0; i < V; i++) {
    	for(auto it: adj[i]) {
    		int v = it.first;
    		int wt = it.second;
    		dist[i][v] = wt;
    	}
    }
    
    // Flyod Warhsall
    for(int via = 0; via < V; via++) {
    	for(int j = 0; j < V; j++) {
    		for(int k = 0; k < V; k++) {
    			dist[j][k] = min(dist[j][k], dist[j][via] + dist[via][k]);
    		}
    	}
    }
}

void solve(vector<vector<int>> dist) {
	int T;
	int n = dist.size();
	cout << "enter the number of test cases: ";
	cin >> T;
	while(T--) {
		int u,v;
		cout << "Enter edges: ";
		cin >> u >> v;
		if(u >= 0 && u < n && v >= 0 && v < n) {
			cout << "dist is: " << dist[u][v] << endl;
		}
		else cout << "Invalid Edges" << endl;
	}
}

int main() {
    int n;
    cout << "Enter the number of vertices: ";
    cin >> n;
    vector<pair<int,int>> adj[n];
    int E;
    cout << "Enter the number of edges: ";
    cin >> E;
    cout << "Enter edges: " << endl;
    for(int i = 0; i < E; i++) {
    	int u,v,w;
    	cin >> u >> v >> w;
    	adj[u].push_back({v,w});
    }
    
    vector<vector<int>> dist(n,vector<int>(n, 1e8));
    
    flyodWarshall(n, adj, dist);
    solve(dist);
}
