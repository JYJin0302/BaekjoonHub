#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll A[100001];
vector<int> adj[100001];
vector<ll> dp;

int n, k;
ll tar, cnt;
void dfs(int v, int pv = -1) {

	ll tot = A[v];
	vector<ll> tmp;

	for (auto i : adj[v]) if (i != pv) {
		dfs(i, v);
		tmp.push_back(dp[i]);
		tot += dp[i];
	}

	if (tot <= tar) {
		dp[v] = tot;
		return;
	}

	sort(tmp.rbegin(), tmp.rend());

	int ix = 0;
	while (ix < tmp.size() && tot > tar) {
		tot -= tmp[ix];
		ix++;
		cnt++;
	}
	dp[v] = tot;

}

void solve() {

	cin >> n >> k;

	ll l = 0, r = 0;
	for (int i = 1; i <= n; i++) adj[i].clear();

	for (int i = 1; i <= n; i++) {
        cin >> A[i];
        l = max(l, A[i]);
        r += A[i];
    }

	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	ll ans = -1;
	while (l <= r) {

		dp = vector<ll>(n + 1);
		tar = (l + r) / 2;
		cnt = 0;
		dfs(1);

		if (cnt <= k) {
			ans = tar;
			r = tar - 1;
		}
		else l = tar + 1;
	}

	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}