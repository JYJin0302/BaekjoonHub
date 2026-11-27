#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> adj[500001];
ll val[500001][3];
ll dp[500001][3];

int ans[500001];

void dfs(int v, int pv = -1) {
	ll a0 = 0, a1 = 0, a2 = 0;
	for (auto i : adj[v]) if (i != pv) {
		dfs(i, v);

		a0 += max(dp[i][1], dp[i][2]);
		a1 += max(dp[i][2], dp[i][0]);
		a2 += max(dp[i][0], dp[i][1]);
	}

	dp[v][0] = a0 + val[v][0];
	dp[v][1] = a1 + val[v][1];
	dp[v][2] = a2 + val[v][2];
}

void solve(int v, int pv, int rs) {
	ans[v] = rs;
	for (auto i : adj[v]) if (i != pv) {
		int ansi = -1, ansv = -1;
		for (int j = 0; j < 3; j++) {
			if (j == rs) continue;
			if (dp[i][j] > ansv) {
				ansv = dp[i][j];
				ansi = j;
			}
		}

		solve(i, v, ansi);
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> val[i][j];
		}
	}

	dfs(1);

	int ansi = -1, ansv = -1;
	for (int i = 0; i < 3; i++) {
		if (ansv < dp[1][i]) {
			ansv = dp[1][i];
			ansi = i;
		}
	}

	solve(1, -1, ansi);

	string tmp = "RGB";
	cout << dp[1][ansi] << '\n';
	for (int i = 1; i <= n; i++) cout << tmp[ans[i]];

}