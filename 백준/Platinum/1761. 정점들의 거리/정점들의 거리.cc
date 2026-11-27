#include <bits/stdc++.h>
using ll = long long;
using namespace std;

#define INF 100000000
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vi>
#define vl vector<ll>
#define vvl vector<vl>
#define vpi vector<pii>
#define vvpi vector<vpi>

int dx[] = { 0, -1, 0, 1 };
int dy[] = { 1, 0, -1, 0 };


vl path, depth;
vvi dp;
vvpi adj;

void dfs(int v, int pv = -1) {
	for (auto i : adj[v]) {
		int a, b;
		tie(a, b) = i;
		if (a != pv) {
			path[a] = path[v] + b;
			depth[a] = depth[v] + 1;
			dfs(a, v);
			
			dp[a][0] = v;
		}
	}
}

void solve() {

	int n;
	cin >> n;

	int logn = log2(n);
	path = vl(n + 1);
	depth = vl(n + 1);
	dp = vvi(n + 1, vi(logn + 1));
	adj = vvpi(n + 1);

	for (int i = 0; i < n-1; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		adj[a].push_back({ b, w });
		adj[b].push_back({ a, w });
	}

	depth[1] = 1;
	dfs(1);
	
	for (int i = 1; i <= logn; i++) {
		for (int j = 1; j <= n; j++) {
			dp[j][i] = dp[dp[j][i-1]][i-1];
		}
	}

	int q;
	cin >> q;
	while (q--) {
		int a, b;
		cin >> a >> b;

		int ai = a, bi = b;
		if (depth[a] > depth[b]) swap(a, b);

		int depdiff = depth[b] - depth[a];

		for (int i = 0; depdiff; i++) {
            if (depdiff & 1) b = dp[b][i];
            depdiff /= 2;
		}
		
		for (int i = logn; i >= 0; i--) {
			if (dp[a][i] != dp[b][i]) {
				a = dp[a][i];
				b = dp[b][i];
			}
		}

		int lca = dp[a][0];
		if (a == b) lca = a;

		cout << path[ai] + path[bi] - 2 * path[lca] << '\n';
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T = 1;
	//cin >> T;

	while (T--) {
		solve();
	}
}