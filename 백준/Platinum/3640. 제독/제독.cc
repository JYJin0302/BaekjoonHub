#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int flow[2001][2001], cap[2001][2001];
vector<pair<int, int>> adj[2001];

int dist[2001], from[2001];
bool inQ[2001];

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	while (cin >> n >> m) {

		for (int i = 1; i <= 2*n; i++) {
			adj[i].clear();
			for (int j = 1; j <= 2*n; j++) {
				flow[i][j] = 0;
				cap[i][j] = 0;
			}
		}

		for (int i = 0; i < m; i++) {
			int a, b, c;
			cin >> a >> b >> c;

			adj[a+n].push_back({ b, c });
			adj[b].push_back({ a + n, -c });
			cap[a+n][b] = 1;
		}

		for (int i = 1; i <= n; i++) {
			adj[i].push_back({ i + n, 0 });
			adj[i + n].push_back({ i, 0 });
			cap[i][i + n] = 1;
		}
		cap[1][1 + n] = 2;
		cap[n][n * 2] = 2;

		int ans = 0;

		// dinic
		while (1) {
			// flow
			for (int i = 0; i <= n * 2; i++) {
				dist[i] = 1e9;
				from[i] = -1;
				inQ[i] = false;
			}
			dist[1] = 0;
			from[1] = 1;

			queue<int> q;
			q.push(1);
			inQ[1] = 1;
			while (!q.empty()) {

				int a = q.front();
				q.pop();
				inQ[a] = 0;

				for (auto i : adj[a]) if (dist[i.first] > dist[a] + i.second && cap[a][i.first] - flow[a][i.first] > 0){
					dist[i.first] = dist[a] + i.second;
					from[i.first] = a;
					if (!inQ[i.first]) {
						inQ[i.first] = true;
						q.push(i.first);
					}
				}
			}

			if (from[n * 2] == -1) break;

			ans += dist[n * 2];
			int pv = n * 2;
			while (pv != 1) {
				int nv = from[pv];
				flow[nv][pv]++;
				flow[pv][nv]--;
				pv = nv;
			}

		}

		cout << ans << '\n';
	}
}