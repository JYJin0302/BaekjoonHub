#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {

		int k, m, p;
		cin >> k >> m >> p;
		
		vector<vector<int>>adj(m + 1);
		vector<int> topo(m + 1);
		for (int i = 0; i < p; i++) {
			int a, b;
			cin >> a >> b;
			adj[a].push_back(b);
			topo[b]++;
		}

		vector<int> dist(m+1);
		queue<int> q;
		for (int i = 1; i <= m; i++) {
			if (topo[i] == 0) {
				dist[i] = 1;
				q.push(i);
			}
		}

		vector<bool> two(m + 1);

		while (!q.empty()) {

			int a = q.front();
			q.pop();
			if (two[a]) dist[a]++;

			for (int i : adj[a]) {

				if (dist[i] == dist[a]) two[i] = 1;
				else if (dist[i] < dist[a]) {
					two[i] = 0;
					dist[i] = dist[a];
				}

				topo[i]--;
				if (topo[i] == 0) q.push(i);
			}
		}

		cout << k << ' ' << dist[m] << '\n';
	}
}