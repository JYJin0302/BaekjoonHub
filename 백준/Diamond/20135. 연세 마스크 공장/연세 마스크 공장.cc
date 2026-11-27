#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define INF 1000000000

ll path[202][202];
ll flow[202][202];


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll n, m;
	cin >> n >> m;

	vector<ll> ss(n + 1);

	for (int i = 1; i <= n; i++) {
		cin >> ss[i];
	}

	vector<tuple<ll, ll, ll, ll>> edge(m);
	for (int i = 0; i < m; i++) {
		ll a, b, c, d;
		cin >> a >> b >> c >> d;
		edge[i] = { a, b, c, d };
		path[a][b] = d - c;
		ss[b] += c;
		ss[a] -= c;
	}

	ll source = 0, sink = 0;
	// 0 : source, n+1: sink
	for (int i = 1; i <= n; i++) {
		if (ss[i] > 0) path[0][i] = ss[i], source += ss[i];
		if (ss[i] < 0) path[i][n + 1] = -ss[i], sink -= ss[i];
	}

	if (source != sink) {
		cout << -1;
		return 0;
	}

	ll max_flow = 0;

	while (1) {

		vector<int> from(n + 2, -1);
		queue<int> q;
		q.push(0);
		from[0] = 0;
		while (!q.empty()) {

			int a = q.front();
			q.pop();

			if (a == n + 1) break;

			for (int i = 0; i <= n + 1; i++) {
				if (path[a][i] - flow[a][i] > 0 && from[i] == -1) {
					from[i] = a;
					q.push(i);
				}
			}
		}

		if (from[n + 1] == -1) break;

		int x = n + 1;
		ll tflow = INF;
		while (x != 0) {
			tflow = min(tflow, path[from[x]][x] - flow[from[x]][x]);
			x = from[x];
		}

		x = n + 1;
		while (x != 0) {
			flow[from[x]][x] += tflow;
			flow[x][from[x]] -= tflow;
			x = from[x];
		}

		max_flow += tflow;
	}

	if (max_flow != source) cout << -1;
	else {
		cout << "1\n";
		for (int i = 0; i < m; i++) {
			ll a, b, c, d;
			tie(a, b, c, d) = edge[i];

			cout << c + flow[a][b] << '\n';
		}
	}
}