#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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

	int s, d;
	cin >> s >> d;

	ll l = 0, r = 1000000000, ans = 0;

	vector<bool> v(n + 1);

	while (l <= r) {

		ll mid = (l + r) / 2;

		v = vector<bool>(n + 1);
		v[s] = 1;

		queue<int> q;
		q.push(s);

		while (!q.empty()) {

			int a = q.front();
			q.pop();
			if (a == d) break;


			for (auto i : adj[a]) {
				int x, y;
				tie(x, y) = i;

				if (y >= mid && !v[x]) {
					v[x] = 1;
					q.push(x);
				}
			}
		}

		if (v[d]) ans = mid, l = mid + 1;
		else r = mid - 1;

	}

	cout << ans;
}