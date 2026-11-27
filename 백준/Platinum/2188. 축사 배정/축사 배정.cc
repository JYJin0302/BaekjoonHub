#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<int>> adj;

int c[402][402];
int f[402][402];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	adj = vector<vector<int>>(402);
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		while (k--) {
			int x;
			cin >> x;

			x += 200;
			adj[i].push_back(x);
			adj[x].push_back(i);
			c[i][x] = 1;
		}
	}

	for (int i = 1; i <= n; i++) {
		adj[0].push_back(i);
		c[0][i] = 1;
	}

	for (int i = 1; i <= m; i++) {
		adj[i + 200].push_back(401);
		c[i + 200][401] = 1;
	}

	int ans = 0;
	while (1) {

		vector<int> from(402, -1);
		from[0] = 0;
		queue<int> q;
		q.push(0);

		while (!q.empty()) {

			int a = q.front();
			q.pop();

			if (a == 401) break;
			for (auto i : adj[a]) if (from[i] == -1 && c[a][i] - f[a][i] > 0) {
				from[i] = a;
				q.push(i);
			}
		}

		if (from[401] == -1) break;

		ans++;

		int x = 401;
		while (x != 0) {
			f[from[x]][x]++;
			f[x][from[x]]--;
			x = from[x];
		}
	}

	cout << ans;

}