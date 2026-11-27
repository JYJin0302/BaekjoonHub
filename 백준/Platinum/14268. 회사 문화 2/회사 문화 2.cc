#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> L, R, seg, lazy;

void dfs(int v, int& cnt) {
	L[v] = cnt++;
	for (int i : adj[v]) {
		dfs(i, cnt);
	}
	R[v] = cnt++;
}

void update(int l, int r, int n, int ul, int ur, int v) {

	if (l > ur || r < ul) return;
	if (l >= ul && r <= ur) {
		lazy[n] += v;
		return;
	}

	int mid = (l + r) / 2;
	update(l, mid, n * 2, ul, ur, v);
	update(mid + 1, r, n * 2 + 1, ul, ur, v);
}

void solve(int l, int r, int n, int s) {

	if (lazy[n] != 0) {
		if (l == r) seg[n] += lazy[n];
		else {
			lazy[n * 2] += lazy[n];
			lazy[n * 2 + 1] += lazy[n];
		}
		lazy[n] = 0;
	}

	if (l > s || r < s) return;
	if (l == s && r == s) return;

	int mid = (l + r) / 2;
	solve(l, mid, n * 2, s);
	solve(mid + 1, r, n * 2 + 1, s);
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
	lazy = vector<int>(size * 2);
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

			update(size, size * 2 - 1, 1, size + L[a], size + R[a], x);
		}
		else {

			int x;
			cin >> x;

			solve(size, size * 2 - 1, 1, size + L[x]);
			cout << seg[size + L[x]] << '\n';
		}
	}
}