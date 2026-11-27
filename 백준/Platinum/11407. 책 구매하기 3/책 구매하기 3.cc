#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int F[210][210], C[210][210];
int cost[210][210];

int dist[211], from[211];
bool inQ[211];

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<int> A(n), B(m);
	for (auto& i : A) cin >> i;
	for (auto& i : B) cin >> i;

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> C[i][j + m];
		}
	}

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> cost[i][j + m];
			cost[j + m][i] = -cost[i][j + m];
		}
	}

	for (int i = 1; i <= n; i++) {
		C[i + m][n+m+1] = A[i-1];
	}

	for (int i = 1; i <= m; i++) {
		C[0][i] = B[i-1];
	}

	// flow from 0 to n+m+1

	int ans_cnt = 0, ans_cost = 0;
	while (1) {
		for (int i = 0; i <= n + m + 1; i++) {
			dist[i] = 1e9;
			from[i] = -1;
			inQ[i] = false;
		}

		queue<int> q;
		q.push(0);
		inQ[0] = 1;
		from[0] = 0;
		dist[0] = 0;
		while (!q.empty()) {
			int a = q.front();
			q.pop();
			inQ[a] = false;

			for (int j = 0; j <= n + m + 1; j++) {
				if (dist[j] > dist[a] + cost[a][j] && C[a][j] - F[a][j] > 0) {
					dist[j] = dist[a] + cost[a][j];
					from[j] = a;
					if (!inQ[j]) {
						inQ[j] = 1;
						q.push(j);
					}
				}
			}
		}

		if (from[n + m + 1] == -1) break;

		int ans_f = 1e9;
		int pv = n + m + 1;

		//cout << "ROUTE: " << dist[n+m+1] << "\n";
		while (pv != 0) {
			//cout << pv << ' ';
			int nv = from[pv];
			ans_f = min(ans_f, C[nv][pv] - F[nv][pv]);
			pv = nv;
		}
		//cout << 0 << " : " << ans_f<< '\n';

		ans_cnt += ans_f;
		ans_cost += ans_f * dist[n + m + 1];
		pv = n + m + 1;
		while (pv != 0) {
			int nv = from[pv];
			F[nv][pv] += ans_f;
			F[pv][nv] -= ans_f;
			pv = nv;
		}

	}

	cout << ans_cnt << '\n' << ans_cost << '\n';
}