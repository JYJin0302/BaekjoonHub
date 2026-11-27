#include <bits/stdc++.h>
using namespace std;


int n, m, a, b, ans, temp;
vector<vector<int>> base;
vector<vector<int>> rebase;
vector<int> nodes;
vector<bool> check;
vector<bool> tempv;
bool ok;

void dfs1(int v = 0) {
	for (int i : base[v]) {
		if (check[i]) continue;
		check[i] = 1;
		dfs1(i);
	}
	nodes.push_back(v);
}

void dfs2(int v) {
	
	for (int i : rebase[v]) {
		if (check[i]) continue;
		if (tempv[abs(i - n)]) {
			ok = false;
			return;
		}
		check[i] = 1;
		tempv[abs(i - n)] = 1;

		dfs2(i);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	
	cin >> n >> m;

	base = vector<vector<int>>(2 * n + 1);
	rebase = vector<vector<int>>(2 * n + 1);

	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		base[n - a].push_back(n+b);
		base[n - b].push_back(n + a);
		rebase[n + b].push_back(n - a);
		rebase[n + a].push_back(n - b);
	}


	check = vector<bool>(2*n + 1);
	for (int i = 0; i < 2 * n + 1; i++) {
		if (i == n) continue;
		if (check[i]) continue;
		check[i] = 1;
		dfs1(i);
	}

	check = vector<bool>(2*n+1);
	for (int i = 0; i < 2 * n; i++) {
		int t = nodes[2 * n - 1 - i];

		if (check[t]) continue;
		check[t] = 1;

		ok = true;
		tempv = vector<bool>(n + 1);

		tempv[abs(t - n)] = 1;
		dfs2(t);
		if (!ok) break;
	}

	cout << (ok ? 1 : 0);

}