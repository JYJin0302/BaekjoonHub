#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {

	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;

	vector<bool> house(n + 1, 1);
	vector<int> d_M(n + 1, -1), d_S(n + 1, -1);
	vector<vector<pair<int, int>>> adj(n+1);

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({ b, c });
		adj[b].push_back({ a, c });
	}

	int t, x;
	cin >> t >> x;

	priority_queue<pair<int, int>> pq;

	// mcdonald
	for (int i = 0; i < t; i++) {
		int k;
		cin >> k;

		house[k] = 0;
		pq.push({ 0, k });
	}

	while (!pq.empty()) {

		int a, b;
		tie(a, b) = pq.top();
		pq.pop();

		if (-a > x) continue;

		if (d_M[b] != -1) continue;
		d_M[b] = -a;

		for (auto i : adj[b]) {

			int x, y;
			tie(x, y) = i;
			
			if (d_M[x] == -1) {
				pq.push({ a - y, x });
			}
		}
	}
	
	
	cin >> t >> x;
	for (int i = 0; i < t; i++) {
		int k;
		cin >> k;

		house[k] = 0;
		pq.push({ 0, k });
	}

	while (!pq.empty()) {

		int a, b;
		tie(a, b) = pq.top();
		pq.pop();

		if (-a > x) continue;
		if (d_S[b] != -1) continue;
		d_S[b] = -a;

		for (auto i : adj[b]) {

			int x, y;
			tie(x, y) = i;

			if (d_S[x] == -1) {
				pq.push({ a - y, x });
			}
		}
	}

	int ans = 1e9 + 1;
	for (int i = 1; i <= n; i++) {
		if (house[i] && d_M[i] != -1 && d_S[i] != -1) ans = min(ans, d_M[i] + d_S[i]);
	}

	if (ans == 1e9 + 1) ans = -1;
	cout << ans;
}