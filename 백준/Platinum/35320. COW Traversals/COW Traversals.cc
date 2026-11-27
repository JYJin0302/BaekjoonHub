#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

int root[202020];
int sz[202020];
int find(int n) {
	if (root[n] == n) return n;
	return root[n] = find(root[n]);
}

void merge(int u, int v) {
	u = find(u);
	v = find(v);
	if (u == v) return;
	root[v] = u;
	sz[u] += sz[v];
}

vector<int> Hst[202020];

void solve() {
	int n;
	cin >> n;
	vector<int> P(n + 1);
	for (int i = 1; i <= n; i++) cin >> P[i];

	vector<int> cyc(n + 1);
	// find cycle
	vector<int> vis(n + 1);
	for (int i = 1; i <= n; i++) {
		if (vis[i]) continue;
		vis[i] = i;
		int cur = i;
		while (1) {
			cur = P[cur];
			if (vis[cur]) {
				if (vis[cur] == i) {
					// cycle found
					int tar = cur;
					while (cyc[cur] == 0) {
						cyc[cur] = tar;
						cur = P[cur];
					}
				}
				break;
			}
			vis[cur] = i;
		}
	}

	int m;
	cin >> m;

	vector<pair<int, int>> Q(m);

	vector<int> firstHost(n + 1, -1);
	vector<int> firstCycle(n + 1, -1);

	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		char c;
		cin >> c;

		int tx = 0;
		if (c == 'O') tx = 1;
		else if (c == 'W') tx = 2;

		Q[i] = mp(x, tx);

		Hst[x].push_back(tx);
		if (firstHost[x] == -1) firstHost[x] = i;

		if (cyc[x]) {
			if (firstCycle[cyc[x]] == -1) {
				firstCycle[cyc[x]] = x;
				P[x] = x;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		sz[i] = 1;
		root[i] = i;
	}

	for (int j = 1; j <= n; j++) {
		if (firstHost[j] == -1) { merge(P[j], j); }
	}

	vector<int> pre(n + 1, -1);
	vector<int> upd(m);
	vector<int> curState(n + 1, -1);

	for (int j = m - 1; j >= 0; j--) {
		auto [a, b] = Q[j];

		upd[j] = sz[a];

		if (firstHost[a] == j) {
			merge(P[a], a);
			int ta = find(a);
			if (ta != a) pre[a] = ta;
		}
	}
	array<int, 3> cur = {0, 0, 0};
	for (int j = 0; j < m; j++) {
		int s = upd[j];
		auto [a, b] = Q[j];

		cur[b] += s;
		if (pre[a] != -1 && firstHost[a] == j) {
			// update
			int prev = curState[pre[a]];
			if (prev != -1) cur[prev] -= s;
		} else if (j != firstHost[a]) {
			int prev = curState[a];
			cur[prev] -= s;
		}
		curState[a] = b;

		for (int i = 0; i < 3; i++) cout << cur[i] << ' ';
		cout << '\n';
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 1;
	// cin >> t;
	while (t--) { solve(); }
	return 0;
}