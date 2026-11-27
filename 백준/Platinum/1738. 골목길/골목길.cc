#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

int G[101][101];
vector<pair<int, int>> adj[101];

int n, m;
vector<int> route;
bool vis[101];

void dfs(int v) {
	route.push_back(v);
	vis[v] = 1;
	if (v == n) {
		for (auto f : route) { cout << f << ' '; }
		cout << '\n';

		exit(0);
	}

	for (auto [a, b] : adj[v]) {
		if (!vis[a] && G[a][n] + b == G[v][n]) { dfs(a); }
	}
	route.pop_back();
}

const int INF = 10101010;
void solve() {
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) { G[i][j] = -INF; }
		G[i][i] = 0;
	}

	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		G[a][b] = max(G[a][b], c);
		adj[a].push_back(mp(b, c));
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) { G[j][k] = max(G[j][k], G[j][i] + G[i][k]); }
		}
	}

	if (G[1][n] == -INF) {
		cout << -1 << '\n';
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (G[i][i] > 0 && G[1][i] > -INF/20 && G[i][n] > -INF/20) {
			cout << -1 << '\n';
			return;
		}
	}

	dfs(1);
	assert(0);
}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 1;
	// cin >> t;
	for (int i = 1; i <= t; i++) { solve(); }
	return 0;
}