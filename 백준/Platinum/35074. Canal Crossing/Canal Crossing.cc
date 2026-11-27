#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

vector<pair<ll, ll>> adj[101010];
int deg[101010];

ll ans = 0;
void dfs(int v, int pv = -1) {
	for (auto [f, w] : adj[v])
		if (f != pv) {
			dfs(f, v);
			if (deg[f]) ans += w;
			deg[v] ^= deg[f];
		}
}

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back(mp(b, c));
		adj[b].push_back(mp(a, c));
	}

	int m;
	cin >> m;
	while (m--) {
		int a, b;
		cin >> a >> b;
		deg[a] ^= 1;
		deg[b] ^= 1;
	}

	dfs(1);

	cout << ans << '\n';
}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 1;
	// cin >> t;
	for (int i = 1; i <= t; i++) {
		// cout << "Case #" << i << ": ";
		solve();
	}

	return 0;
}