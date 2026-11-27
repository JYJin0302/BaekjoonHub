#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<int>> adj;

int c[2002][2002];
int f[2002][2002];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;
	cin >> N >> M;

	adj = vector<vector<int>>(2002);
	for (int i = 1; i <= N; i++) {
		int k;
		cin >> k;
		while (k--) {
			int x;
			cin >> x;

			x += 1000;
			adj[i].push_back(x);
			adj[x].push_back(i);
			c[i][x] = 1;
		}
	}

	for (int i = 1; i <= N; i++) {
		adj[0].push_back(i);
		c[0][i] = 2;
	}

	for (int i = 1; i <= M; i++) {
		adj[i + 1000].push_back(2001);
		c[i + 1000][2001] = 1;
	}

	int ans = 0;
	while (1) {

		vector<int> from(2002, -1);
		from[0] = 0;
		queue<int> q;
		q.push(0);

		while (!q.empty()) {

			int a = q.front();
			q.pop();

			if (a == 2001) break;
			for (auto i : adj[a]) if (from[i] == -1 && c[a][i] - f[a][i] > 0) {
				from[i] = a;
				q.push(i);
			}
		}

		if (from[2001] == -1) break;

		ans++;

		int x = 2001;
		while (x != 0) {
			f[from[x]][x]++;
			f[x][from[x]]--;
			x = from[x];
		}
	}

	cout << ans;
}