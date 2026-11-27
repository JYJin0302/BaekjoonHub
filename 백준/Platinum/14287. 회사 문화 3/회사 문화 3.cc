#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> L, R, seg;

void dfs(int v, int& cnt) {
	L[v] = cnt++;
	for (int i : adj[v]) {
		dfs(i, cnt);
	}
	R[v] = cnt++;
}

void update(int l, int r, int n, int u, int v) {

	if (l > u || r < u) return;
	if (l == u && r == u) {
		seg[n] += v;
		return;
	}

	int mid = (l + r) / 2;
	update(l, mid, n * 2, u, v);
	update(mid + 1, r, n * 2 + 1, u, v);
	seg[n] = seg[n * 2] + seg[n * 2 + 1];
}

int solve(int l, int r, int n, int sl, int sr) {

	if (l > sr || r < sl) return 0;
	if (l >= sl && r <= sr) return seg[n];

	int mid = (l + r) / 2;
	int n1 = solve(l, mid, n * 2, sl, sr);
	int n2 = solve(mid + 1, r, n * 2 + 1, sl, sr);
	return (n1 + n2);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;

	L = vector<int>(n + 1);
	R = vector<int>(n + 1);
	adj = vector<vector<int>>(n + 1);
	

	int size = 1;
	while (size < n * 2) size *= 2;
	seg = vector<int>(size * 2);

	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		if (x != -1) adj[x].push_back(i);
	}
	int cnt = 0;
	dfs(1, cnt);

	for (int i = 0; i < m; i++) {
		int t;
		cin >> t;
		if (t == 1) {
			int a, x;
			cin >> a >> x;

			update(size, size * 2 - 1, 1, size + L[a], x);
			update(size, size * 2 - 1, 1, size + R[a], x);
		}
		else {

			int x;
			cin >> x;
			
			cout << solve(size, size * 2 - 1, 1, size + L[x], size + R[x])/2 << '\n';
		}
	}
}