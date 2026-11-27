#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll dist(pair<ll, ll> x, pair<ll, ll> y) {
	return ceil(sqrt(pow(x.first - y.first, 2) + (double)pow(x.second - y.second, 2)));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	pair<ll, ll> s, d;
	cin >> s.first >> s.second;
	cin >> d.first >> d.second;

	ll B;
	cin >> B;

	ll t0;
	cin >> t0;

	ll T;
	cin >> T;

	vector<ll> cost(T + 1);
	cost[0] = t0;
	for (int i = 1; i <= T; i++) cin >> cost[i];

	ll N;
	cin >> N;
	vector<pair<ll, ll>> station(N);
	vector<vector<pair<ll, ll>>> adj(N);
	for (int i = 0; i < N; i++) {
		ll a, b;
		cin >> a >> b;
		station[i] = { a, b };

		ll k;
		cin >> k;

		while (k--) {
			ll x, y;
			cin >> x >> y;
			adj[i].push_back({ x, y });
			adj[x].push_back({ i, y });
		}
	}
	if (dist(s, d) > B) {
		cout << -1;
		return 0;
	}

	// find path
	ll ans = cost[0] * dist(s, d);
	
	vector<vector<ll>> path(N, vector<ll>(B + 1, -1));
	
	priority_queue<tuple<ll, ll, ll>> pq;  // cost, km, place
	for (int i = 0; i < N; i++) {
		ll d = dist(s, station[i]);
		if (d <= B) pq.push({ -d * cost[0], d, i });
	}

	while (!pq.empty()) {

		ll a, b, c;
		tie(a, b, c) = pq.top();
		pq.pop();
		

		a *= -1;
		if (path[c][b] != -1) continue;
		path[c][b] = a;
		

		ll td = dist(d, station[c]);
		if (b + td <= B) ans = min(ans, a + cost[0] * dist(d, station[c]));

		for (auto i : adj[c]) {

			ll x, y;
			tie(x, y) = i;

			ll nd = dist(station[x], station[c]);

			if (b + nd <= B && path[x][b + nd] == -1) {
				pq.push({ -(a + nd * cost[y]), b + nd, x });
			}
		}
	}

	cout << ans;
}