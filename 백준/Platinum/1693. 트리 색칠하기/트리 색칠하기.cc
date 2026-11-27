#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000

int logn;
vector<vector<int>> adj;
vector<vector<int>> dp;

void dfs(int v, int pv = -1) {

	for (int i : adj[v]) if (i != pv) {
		dfs(i, v);
		for (int j = 1; j <= logn; j++) {
			int tt = INF;
			for (int k = 1; k <= logn; k++) {
				if (j != k) tt = min(tt, dp[i][k]);
			}
			dp[v][j] += tt;
		}
	}

	for (int i = 1; i <= logn; i++) {
		dp[v][i] += i;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;

	logn = log2(n) + 1;

	adj = vector<vector<int>>(n + 1);
	dp = vector<vector<int>>(n + 1, vector<int>(logn + 1));
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;

		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	dfs(1);

	int ans = INF;
	for (int i = 1; i <= logn; i++) {
		ans = min(ans, dp[1][i]);
	}
	cout << ans;
}