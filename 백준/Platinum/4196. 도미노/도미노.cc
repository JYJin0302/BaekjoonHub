#include <bits/stdc++.h>
using namespace std;

int t, n, m, a, b;
vector<vector<int>> base;
vector<vector<int>> rebase;
vector<int> nodes;
vector<bool> check;


void dfs1(int v = 0) {
	for (int i : base[v]) {
		if (check[i]) continue;
		check[i] = 1;
		dfs1(i);
	}
	nodes.push_back(v);
}

void dfs2(int v = 0) {
	for (int i : rebase[v]) {
		if (check[i]) continue;
		check[i] = 1;
		dfs2(i);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> t;
	while (t--) {

		cin >> n >> m;

		base = vector<vector<int>>(n + 1);
		rebase = vector<vector<int>>(n + 1);

		for (int i = 0; i < m; i++) {
			cin >> a >> b;
			base[a].push_back(b);
			rebase[b].push_back(a);
		}

		check = vector<bool>(n + 1);
		for (int i = 1; i <= n; i++) {
			if (check[i]) continue;
			check[i] = 1;
			dfs1(i);
		}


		int cnt = 0;
		check = vector<bool>(n + 1);
		for (int i = 0 ; i < n; i++) {
			int t = nodes[n - 1 - i];

			if (check[t]) continue;
			check[t] = 1;

			dfs1(t);
			cnt++;

		}

		cout << cnt << '\n';
		nodes.clear();
	}
}