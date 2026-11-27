#include <bits/stdc++.h>
using namespace std;

int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);
	int n, m;
	cin >> n >> m;

	vector<vector<pair<int, int>>> adj(n + 1), rev(n+1);
	vector<int> topo(n + 1);
	for (int i = 0; i < m; i++) {
		int a, b, d;
		cin >> a >> b >> d;
		adj[a].push_back({ b, d });
		topo[b]++;
		rev[b].push_back({ a, d });
	}

	int s, d;
	cin >> s >> d;

	vector<int> dist(n + 1);
	// 위상정렬
	queue<int> q;
	q.push(s);
	while (!q.empty()) {
		int a = q.front();
		q.pop();

		for (auto i : adj[a]) {
			int x, y;
			tie(x, y) = i;

			topo[x]--;
			dist[x] = max(dist[x], dist[a] + y);

			if (topo[x] == 0) q.push(x);
		}
	}

	vector<bool> pathfound(n + 1);
	pathfound[d] = 1;
	int ans = 0;
	q.push(d);
	while (!q.empty()) {

		int a = q.front();
		q.pop();
		if (!pathfound[a]) continue;

		for (auto i : rev[a]) {
			int x, y;
			tie(x, y) = i;

			if (dist[x] + y == dist[a]) {
                if (!pathfound[x]) q.push(x);
				pathfound[x] = 1;
				ans++;
			}
		}
	}

	cout << dist[d] << '\n';
	cout << ans << '\n';
}