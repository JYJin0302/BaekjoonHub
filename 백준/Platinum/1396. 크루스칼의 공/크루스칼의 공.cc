#include <bits/stdc++.h>
using namespace std;

// 1, 3, 5, ..., 2n - 1
// 2, 4, 6, ..., 2n - 2


int n, logn, m;
vector<int> C, S, root, dep;
vector<vector<int>> adj;
int find(int n) {
	if (root[n] == n) return n;
	return root[n] = find(root[n]);
}

void dfs(int v, int pv = -1, int d = 1) {
	dep[v] = d;
	for (auto i : adj[v]) if (i != pv) {
		dfs(i, v, d + 1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;

	int ns = 2 * n;
	C = vector<int>(ns + 1);
	S = vector<int>(ns + 1, 1);
	dep = vector<int>(ns + 1);
	adj = vector<vector<int>>(ns + 1);
	root = vector<int>(ns + 1);
	for (int i = 1; i < ns + 1; i++) root[i] = i;

	logn = log2(n) + 1;
	vector<tuple<int, int, int>> edge(m);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		a = a * 2 - 1;
		b = b * 2 - 1;
		edge[i] = { c ,a, b };
	}

	sort(edge.begin(), edge.end());

	vector<vector<int>> dp(ns + 1, vector<int>(logn));

	int cnt = 0;
	for (auto i : edge) {
		int a, b, c;
		tie(a, b, c) = i;

		b = find(b), c = find(c);
		if (b == c) continue;

		cnt++;
		int tx = cnt * 2;
		adj[tx].push_back(b);
		adj[tx].push_back(c);
		adj[b].push_back(tx);
		adj[c].push_back(tx);
		
		root[b] = tx;
		root[c] = tx;

		dp[b][0] = tx, dp[c][0] = tx;
		C[tx] = a;
		S[tx] = S[b] + S[c];
	}
	for (int i = 1; i <= ns; i++) {
		if (root[i] == i) dfs(i);
	}

	for (int i = 1; i < logn; i++) {
		for (int j = 1; j < ns + 1; j++) {
			dp[j][i] = dp[dp[j][i-1]][i-1];
		}
	}

	int q;
	cin >> q;
	while (q--) {

		int a, b;
		cin >> a >> b;

		a = a * 2 - 1;
		b = b * 2 - 1;

		find(a), find(b);
		if (root[a] != root[b]) {
			cout << "-1\n";
			continue;
		}

		// find lca

		if (dep[a] > dep[b]) swap(a, b);

		int diff = dep[b] - dep[a];
		for (int i = logn - 1; i >= 0; i--) {
			if (diff & (1 << i)) b = dp[b][i];
		}

		for (int i = logn - 1; i >= 0; i--) {
			if (dp[a][i] != dp[b][i]) {
				a = dp[a][i];
				b = dp[b][i];
			}
		}
		a = dp[a][0];

		cout << C[a] << ' ' << S[a] << '\n';

	}
}