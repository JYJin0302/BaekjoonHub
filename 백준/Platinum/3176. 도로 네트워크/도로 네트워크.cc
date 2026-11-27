#include <bits/stdc++.h>
using ll = long long;
using namespace std;

#define INF 100000000
#define pb push_back
#define all(x) (x).begin(),(x).end()

int dx[] = { 0, -1, 0, 1 };
int dy[] = { 1, 0, -1, 0 };

vector<vector<pair<int, int>>> adj;

vector<vector<int>> sparse, maxx, minn;
vector<int> dep;

void dfs(int v, int pv = 0, int d = 1) {

	dep[v] = d;
	for (auto i : adj[v]) {
		if (i.first != pv) {

			dfs(i.first, v, d + 1);
			maxx[0][i.first] = i.second;
			minn[0][i.first] = i.second;
			sparse[0][i.first] = v;
		}
	}
}

void solve() {

	int n;
	cin >> n;

	int logn = log2(n) + 1;

	sparse = vector<vector<int>>(logn, vector<int>(n+1));
	maxx = vector<vector<int>>(logn, vector<int>(n+1));
	minn = vector<vector<int>>(logn, vector<int>(n+1, INF));
	adj = vector<vector<pair<int, int>>>(n + 1);
	dep = vector<int>(n + 1);
	for (int i = 0; i < n - 1; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({ b,c });
		adj[b].push_back({ a, c });
	}
	dfs(1);

	for (int i = 1; i < logn; i++) {
		for (int j = 1; j <= n; j++) {
			sparse[i][j] = sparse[i - 1][sparse[i - 1][j]];
		}
	}
	for (int i = 1; i < logn; i++) {
		for (int j = 1; j <= n; j++) {
			maxx[i][j] = max(maxx[i - 1][j], maxx[i - 1][sparse[i - 1][j]]);
		}
	}

	for (int i = 1; i < logn; i++) {
		for (int j = 1; j <= n; j++) {
			minn[i][j] = min(minn[i - 1][j], minn[i - 1][sparse[i - 1][j]]);
		}
	}

	int q;
	cin >> q;
	while (q--) {
		int a, b;
		cin >> a >> b;

		int ia = a, ib = b;

		if (dep[a] > dep[b]) swap(a, b);
		int diff = dep[b] - dep[a];
		for (int i = 0; i < logn; i++) {
			if ((1 << i) & diff) b = sparse[i][b];
		}

		for (int i = logn - 1; i >= 0; i--) {
			if (sparse[i][a] != sparse[i][b]) {
				a = sparse[i][a], b = sparse[i][b];
			}
		}

		int lca = -1;
		if (a != b) lca = sparse[0][a];
		else lca = a;

		int ansmin = INF, ansmax = 0;
		diff = dep[ia] - dep[lca];
		for (int i = 0; i < logn; i++) {
			if ((1 << i) & diff) {
				ansmin = min(ansmin, minn[i][ia]);
				ansmax = max(ansmax, maxx[i][ia]);
				ia = sparse[i][ia];
			}
		}
		diff = dep[ib] - dep[lca];
		for (int i = 0; i < logn; i++) {
			if ((1 << i) & diff) {
				ansmin = min(ansmin, minn[i][ib]);
				ansmax = max(ansmax, maxx[i][ib]);
				ib = sparse[i][ib];
			}
		}

		cout << ansmin << ' ' << ansmax << '\n';
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