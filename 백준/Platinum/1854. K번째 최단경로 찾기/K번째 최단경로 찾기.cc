#include <bits/stdc++.h>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, k;
	cin >> n >> m >> k;

	vector<vector<pair<int, int>>> adj(n + 1);
	vector<vector<int>> path(n + 1);
	

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		adj[a].push_back({ b,c });
	}

	priority_queue<pair<int, int>> pq;
	pq.push({ 0, 1 });

	while (!pq.empty()) {

		int a, b;
		tie(a, b) = pq.top();
		pq.pop();

		if (path[b].size() >= k) continue;
		path[b].push_back(-a);

		for (auto i : adj[b]) {
			int x, y;
			tie(x, y) = i;

			if (path[x].size() < k) {
				pq.push({ a - y, x });
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		if (path[i].size() != k) cout << -1 << '\n';
		else cout << path[i][k - 1] << '\n';
	}

}