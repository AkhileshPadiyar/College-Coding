#include <bits/stdc++.h>
using namespace std;

bool adjust(vector<int> &a, int idx, vector<int> b) {
    
    while(true) {
        if(idx == 0)    return true;
    
        if(a[idx] >= a[idx - 1]) return true;
    
        a[idx - 1] = b[0] - a[idx - 1];
    
        if(a[idx - 1] > a[idx]) return false;
    
        idx = idx - 1;
    }
}


void solve() {
    int n, m;
    cin >> n >> m;
    vector<int > a(n);
    for(int i = 0; i < n; i++){
        int ele;
        cin >> ele;
        a[i] = ele;
    }
    vector<int> b(1);
    for(int i = 0; i < m; i++){
        int ele;
        cin >> ele;
        b[i] = ele;
    }
    
    for(int i = 1; i < n; i++) {
        if(!adjust(a, i, b)){
            cout << "No";
            return;
        }
    }
    cout << "Yes";
}

int main() {
	
	
	int T;
	cin >> T;
	while(T--) {
	    solve();
	    cout << endl;
	}

}
