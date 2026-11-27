#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define INF 100000000

ll c[802][802];  // 직원 1 ~ 400, 일 401 ~ 800, source: 0, sink: 801
ll f[802][802];
ll cost[802][802];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll n, m;
	cin >> n >> m;

	vector<vector<ll>> adj(802);

	for (int i = 1; i <= n; i++) {
		ll x;
		cin >> x;
		while (x--) {
			int a, b;
			cin >> a >> b;

			adj[i].push_back(a + 400);
			adj[a + 400].push_back(i);
			c[i][a + 400] = 1;
			cost[i][a + 400] = b;
			cost[a + 400][i] = -b;
		}
	}

	// source - 직원
	for (int i = 1; i <= n; i++) {
		adj[0].push_back(i);
		c[0][i] = 1;
	}

	// 일 - sink
	for (int i = 1; i <= m; i++) {
		adj[i + 400].push_back(801);
		c[i + 400][801] = 1;
	}

	ll cnt = 0, ans = 0;
	while (1) {

		vector<ll> dist(802, INF), from(802, -1);
		dist[0] = 0, from[0] = 0;

		vector<bool> inQ(802);
		inQ[0] = 1;
		queue<int> q;
		q.push(0);
		while (!q.empty()) {

			ll a = q.front();
			q.pop();
			inQ[a] = 0;

			for (ll i : adj[a]) {
				if (dist[i] > dist[a] + cost[a][i] && c[a][i] - f[a][i] > 0) {

					dist[i] = dist[a] + cost[a][i];
					from[i] = a;

					if (!inQ[i]) {
						
						inQ[i] = 1;
						q.push(i);
					}
				}
			}
		}
		if (from[801] == -1) break;

		ll td = INF;
		ll x = 801;
		while (x != 0) {
			td = min(td, c[from[x]][x] - f[from[x]][x]);
			x = from[x];
		}

		x = 801;
		while (x != 0) {
			f[from[x]][x] += td;
			f[x][from[x]] -= td;
			ans += cost[from[x]][x] * td;
			x = from[x];
		}

		cnt++;
	}
	cout << cnt << '\n' << ans << '\n';

}