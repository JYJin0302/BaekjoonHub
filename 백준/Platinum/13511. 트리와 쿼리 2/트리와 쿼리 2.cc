#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, logn;
vector<ll> dist, dep;
vector<vector<int>> dp;
vector<vector<pair<ll, ll>>> adj;

void dfs(int v, int pv = -1, int d = 1) {
	dep[v] = d;
	for (auto k : adj[v]) {
		ll a, b;
		tie(a, b) = k;
		if (a != pv) {
			dist[a] = dist[v] + b;
			dfs(a, v, d + 1);
			dp[a][0] = v;
		}
	}
}

int lca(int u, int v) {

	if (dep[u] > dep[v]) swap(u, v);

	int diff = dep[v] - dep[u];
	for (int i = 0; i < logn; i++) {
		if (diff & (1 << i)) {
			v = dp[v][i];
		}
	}

	for (int i = logn - 1; i >= 0; i--) {
		if (dp[u][i] != dp[v][i]) {
			u = dp[u][i];
			v = dp[v][i];
		}
	}

	if (u == v) return u;
	return dp[u][0];
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	logn = log2(n) + 1;

	adj = vector<vector<pair<ll, ll>>>(n + 1);
	dist = vector<ll>(n + 1);
	dp = vector<vector<int>>(n + 1, vector<int>(logn));
	dep = vector<ll>(n + 1);

	for (int i = 0; i < n - 1; i++) {
		ll a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({ b, c });
		adj[b].push_back({ a, c });
	}

	dfs(1);

	// set dp
	for (int i = 1; i < logn; i++) {
		for (int j = 1; j <= n; j++) {
			dp[j][i] = dp[dp[j][i - 1]][i - 1];
		}
	}
    
	int q;
	cin >> q;
	while (q--) {

		int t, a, b, k;
		cin >> t;
		if (t == 1) {
			cin >> a >> b;
			int l = lca(a, b);

			cout << dist[b] + dist[a] - 2 * dist[l] << '\n';

		}
		else {
			cin >> a >> b >> k;
			int l = lca(a, b);
			k--;
			int tot = dep[a] + dep[b] - 2 * dep[l];

			if (dep[a] - dep[l] >= k) {

				for (int i = 0; i < logn; i++) {
					if (k & (1 << i)) a = dp[a][i];
				}
				cout << a << '\n';
			}
			else {
				k = tot - k;

				for (int i = 0; i < logn; i++) {
					if (k & (1 << i)) b = dp[b][i];
				}
				cout << b << '\n';
			}


		}
	}
}