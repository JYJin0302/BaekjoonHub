#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> adj[300001];
ll dp[300001];
ll dist[300001];
ll cnt[300001];

ll ans = 0;
void dfs(int v, int pv = -1) {
	cnt[v] = 1;
	for (auto i : adj[v])if (i != pv) {
		dist[i] = dist[v] + 1;
		dfs(i, v);

		ans += cnt[v] * cnt[i] * dist[v];
		ans += dp[i] * cnt[v] + cnt[i]* dp[v];

		dp[v] += dp[i];
		cnt[v] += cnt[i];
	}

	dp[v] += cnt[v];
}

void solve() {

	int n;
	cin >> n;

	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	dfs(1);

	cout << ans;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}
}