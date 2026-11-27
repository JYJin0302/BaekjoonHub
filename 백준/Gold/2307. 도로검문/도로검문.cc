#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {

	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;

	vector<vector<tuple<int, int, int>>> adj(n + 1);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({ b, c, i });
		adj[b].push_back({ a, c, i });
	}

	priority_queue<pair<int, int>> pq;
	vector<int> dist(n + 1, -1);
	int ans = 0;

	queue<int> q;

	pq.push({ 0, 1 });
	while (!pq.empty()) {

		int a, b;
		tie(a, b) = pq.top();
		pq.pop();

		if (dist[b] != -1) continue;
		dist[b] = -a;
		if (b == n) {
			ans = -a;
			break;
		}

		for (auto k : adj[b]) {

			int x, y, z;
			tie(x, y, z) = k;

			if (dist[x] == -1) {
				pq.push({ a - y, x });
			}
		}
	}

	vector<bool> used(m);
	q.push(n);
	while (!q.empty()) {

		int a = q.front();
		q.pop();

		for (auto k : adj[a]) {

			int x, y, z;
			tie(x, y, z) = k;

			if (dist[x] + y == dist[a]) {
				used[z] = 1;
				q.push(x);
			}
		}
	}

	while (!pq.empty()) pq.pop();

	bool impo = 0;
	int maxd = -1;
	for (int i = 0; i < m; i++) {
		if (!used[i]) continue;

		dist = vector<int>(n + 1, -1);

		int nans = -1;
		pq.push({ 0, 1 });
		while (!pq.empty()) {

			int a, b;
			tie(a, b) = pq.top();
			pq.pop();

			if (dist[b] != -1) continue;
			dist[b] = -a;
			if (b == n) {
				nans = -a;
				break;
			}

			for (auto k : adj[b]) {

				int x, y, z;
				tie(x, y, z) = k;
				if (z == i) continue;

				if (dist[x] == -1) {
					pq.push({ a - y, x });
				}
			}
		}
		if (nans == -1) impo = 1;
		else maxd = max(maxd, nans);
		while (!pq.empty()) pq.pop();
	}

	if (maxd == -1 || impo) cout << -1;
	else cout << maxd - ans;

}