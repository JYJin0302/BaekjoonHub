#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> tmp;
vector<pair<int, int>> adj[200001];
bool vs[200001];

void dfs(int v, int it, int pv = -1) {

	int val = 0;
	for (auto i : adj[v]) {
		val = i.second;
		if (!vs[i.first]) {
			vs[i.first] = 1;
			tmp.push_back(i.second);
			dfs(i.first, it, v);
		}
	}

	if (v == it) tmp.push_back(val);

}

void solve() {

	int n;
	cin >> n;

	ll ans = 0;

	for (int i = 0; i < n; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		if (a == b) {
			ans += c;
			vs[a] = 1;
		}
		else {
			adj[a].push_back({ b, c });
			adj[b].push_back({ a, c });
		}
	}

	for (int i = 1; i <= n; i++) {
		if (!vs[i]) {
			vs[i] = 1;
			dfs(i, i);

			/*
			for (auto k : tmp) cout << k << ' ';
			cout << '\n';
			*/

			int sz = tmp.size();
			vector<vector<ll>> dp(sz, vector<ll>(2, 1e10));
			// dp[a][b] : a번째 간선 사용 여부 b
			
			dp[0][1] = tmp[0];
			for (int i = 1; i < sz; i++) {
				dp[i][0] = dp[i - 1][1];
				dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]) + tmp[i];
			}

			ll ans1 = min(dp[sz - 1][0], dp[sz - 1][1]);

			dp = vector<vector<ll>> (sz, vector<ll>(2, 1e10));

			dp[0][0] = 0;
			for (int i = 1; i < sz; i++) {
				dp[i][0] = dp[i - 1][1];
				dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]) + tmp[i];
			}

			ll ans2 = dp[sz - 1][1];

			ans += min(ans1, ans2);
			tmp.clear();
		}
	}
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