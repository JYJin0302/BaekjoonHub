#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	while (!(n == 0 && m == 0)) {

		int s, d;
		cin >> s >> d;

		vector<vector<pair<int, int>>> adj(n), rev(n);
		vector<int> path(n, -1);

		for (int i = 0; i < m; i++) {
			int a, b, c;
			cin >> a >> b >> c;

			adj[a].push_back({ b, c });
			rev[b].push_back({ a, c });
		}

		// find path
		priority_queue<pair<int, int>> pq;
		pq.push({ 0, s });
		while (!pq.empty()) {

			int a, b;
			tie(a, b) = pq.top();
			pq.pop();
			a *= -1;

			if (path[b] != -1) continue;
			path[b] = a;

			for (auto i : adj[b]) {

				int x, y;
				tie(x, y) = i;

				if (path[x] == -1) pq.push({ -(a + y), x });
			}
		}
        

		// check path

		vector<bool> minpath(n);
		queue<int> q;
		q.push(d);
		minpath[d] = 1;
		while (!q.empty()) {
			int a = q.front();
			q.pop();

			for (auto i : rev[a]) {
				int x, y;
				tie(x, y) = i;

				if (path[x] + y == path[a] && !minpath[x]) {
					minpath[x] = 1;
					q.push(x);
				}
			}
		}

		// find ans

		vector<int> ans(n, -1);
		ans[d] = 0;
		for (auto i : rev[d]) {
			int x, y;
			tie(x, y) = i;

			if (path[x] + y != path[d]) pq.push({ -y, x });
		}
		
		while (!pq.empty()) {

			int a, b;
			tie(a, b) = pq.top();
			pq.pop();
			a *= -1;

			if (ans[b] != -1) continue;
			ans[b] = a;

			for (auto i : rev[b]) {

				int x, y;
				tie(x, y) = i;

				if (!minpath[b]) {
					if (ans[x] == -1) pq.push({ -(a + y), x });
				}
				else {
					if (ans[x] == -1 && path[x] + y != path[b]) pq.push({ -(a + y), x });
				}
			}
		}

		cout << ans[s] << '\n';

		cin >> n >> m;
	}
}