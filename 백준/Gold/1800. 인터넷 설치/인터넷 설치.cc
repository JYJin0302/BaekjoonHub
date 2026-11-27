#include <bits/stdc++.h>
using namespace std;

int main() {

	int n, p, k;
	cin >> n >> p >> k;

	vector<vector<pair<int, int>>> adj(n + 1);
	vector<vector<int>> path(k + 1, vector<int>(n+1));

	for (int i = 0; i < p; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		adj[a].push_back({ b, c });
		adj[b].push_back({ a, c });
	}

	vector<vector<bool>> check(k+1, vector<bool>(n + 1));

	priority_queue<tuple<int, int, int>> pq;  // 거리, 이용한 k 개수, 위치
	pq.push({ 0, 0, 1 });

	while (!pq.empty()) {
		int a, b, c;
		tie(a, b, c) = pq.top();
		pq.pop();

		if (c == n) {
			cout << a * -1;
			return 0;
		}

		if (check[b][c]) continue;
		check[b][c] = 1;

		for (auto i : adj[c]) {
			int x, y;
			tie(x, y) = i;

			if (!check[b][x]) pq.push({ min(a, y*-1), b, x });
			if (b < k && !check[b + 1][x]) pq.push({ a, b + 1, x });
		}
	}

	cout << -1;

}