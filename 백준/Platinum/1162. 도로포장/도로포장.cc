#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);
	int n, m, k;
	cin >> n >> m >> k;

	vector<vector<pair<int, int>>> adj(n+1);

	for (int i = 0; i < m; i++) {

		int a, b, c;
		cin >> a >> b >> c;

		adj[a].push_back({ b, c });
		adj[b].push_back({ a,c });

	}

	ll path[10001][21];
	memset(path, -1, sizeof(path));
	priority_queue<tuple<ll, ll, ll>> pq;  // time, cover cnt, city


	ll ans = -1;
	pq.push({ 0, 0, 1 });
	while (!pq.empty()) {

		ll a, b, c;
		tie(a, b, c) = pq.top();
		pq.pop();

		a *= -1;
		if (path[c][b] != -1) continue;
		path[c][b] = a;
		if (c == n) {
			ans = a;
			break;
		}

		for (auto i : adj[c]) {

			ll x, y;
			tie(x, y) = i;

			if (b < k && path[x][b + 1] == -1) pq.push({ -a, b + 1, x });
			if (path[x][b] == -1) pq.push({ -(a + y), b, x });
		}
	}

	cout << ans;
}