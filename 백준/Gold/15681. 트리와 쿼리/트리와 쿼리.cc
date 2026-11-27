#include <bits/stdc++.h>
using namespace std;


vector<vector<int>> base;
vector<int> dp;
int n, r, q, a, b;

void dfs(int v = r, int p = 0) {
	for (int i : base[v]) {
		if (i != p) {
			dfs(i, v);
			dp[v] += dp[i];
		}
	}
	dp[v]++;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> r >> q;

	base = vector<vector<int>>(n+1);
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b;
		base[a].push_back(b);
		base[b].push_back(a);
	}

	dp = vector<int>(n + 1);
	dfs();

	while (q--) {
		cin >> a;
		cout << dp[a] << '\n';
	}
}