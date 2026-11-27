#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int>>> adj;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	adj = vector<vector<pair<int, int>>>(n + 1);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({ b, c });
		adj[b].push_back({ a, c });
	}

	int x, y, z;
	cin >> x >> y >> z;

	vector<int> d_x(n + 1, -1), d_y(n + 1, -1), d_z(n + 1, -1);
	vector<int> f_x(n + 1), f_y(n + 1), f_z(n + 1);

	priority_queue<tuple<int, int, int>> pq;
	// x
	pq.push({ 0, x, x });
	
	while (!pq.empty()) {

		int a, b, c;
		tie(a, b, c) = pq.top();
		pq.pop();

		if (d_x[b] != -1) continue;

		d_x[b] = -a;
		f_x[b] = c;

		for (auto i : adj[b]) {

			int l, r;
			tie(l, r) = i;

			if (d_x[l] == -1) {
				pq.push({ a - r, l , b });
			}
		}
	}

	// y
	pq.push({ 0, y, y });

	while (!pq.empty()) {

		int a, b, c;
		tie(a, b, c) = pq.top();
		pq.pop();

		if (d_y[b] != -1) continue;

		d_y[b] = -a;
		f_y[b] = c;

		for (auto i : adj[b]) {

			int l, r;
			tie(l, r) = i;

			if (d_y[l] == -1) {
				pq.push({ a - r, l , b });
			}
		}
	}
	
	// x
	pq.push({ 0, z, z });

	while (!pq.empty()) {

		int a, b, c;
		tie(a, b, c) = pq.top();
		pq.pop();

		if (d_z[b] != -1) continue;

		d_z[b] = -a;
		f_z[b] = c;

		for (auto i : adj[b]) {

			int l, r;
			tie(l, r) = i;

			if (d_z[l] == -1) {
				pq.push({ a - r, l , b });
			}
		}
	}

	int ans = -1, dist = 1000000;
	for (int i = 1; i <= n; i++) {
		int nd = d_x[i] + d_y[i] + d_z[i];
		if (nd < dist) {
			ans = i;
			dist = nd;
		}
	}

	vector<pair<int, int>> res;
	// x
	for (int i = ans; i != x; i = f_x[i]) {
		res.push_back({ f_x[i], i });
	}
    // y
	for (int i = ans; i != y; i = f_y[i]) {
		res.push_back({ f_y[i], i });
	}
    // z
	for (int i = ans; i != z; i = f_z[i]) {
		res.push_back({ f_z[i], i });
	}

	cout << dist << ' ' << res.size() << '\n';

	for (auto i : res) cout << i.first << ' ' << i.second << '\n';
}