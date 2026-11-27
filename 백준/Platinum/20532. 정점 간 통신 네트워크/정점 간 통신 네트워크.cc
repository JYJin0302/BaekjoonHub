#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX = 100000;

ll M[MAX + 1], D[MAX + 1];

vector<int> val;
vector<vector<int>> adj;

ll ans = 0;

void dfs(int v) {
    
    ll k = val[v];
    // get ans
	ans += D[k];
	for (ll i = 1; i * i <= k; i++) {
		if (k % i == 0) {
			ans += M[i];
			if (i * i != k) ans += M[k / i];
		}
	}
	ans -= M[k];
    
    // update
	M[k]++;
	for (ll i = 1; i * i <= k; i++) {
		if (k % i == 0) {
			D[i]++;
			if (i * i != k) D[k / i]++;
		}
	}
    
	for (auto i : adj[v]) {
		dfs(i);
	}

	// update
	M[k]--;
	for (ll i = 1; i * i <= k; i++) {
		if (k % i == 0) {
			D[i]--;
			if (i * i != k) D[k / i]--;
		}
	}

	

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	
	adj = vector<vector<int>>(n + 1);
	val = vector<int>(n + 1);

	for (int i = 1; i <= n; i++) {
		cin >> val[i];
	}

	for (int i = 2; i <= n; i++) {
		int x;
		cin >> x;
		adj[x].push_back(i);
	}

	dfs(1);

	cout << ans;
}