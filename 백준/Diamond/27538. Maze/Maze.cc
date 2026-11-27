#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(x) begin(x), end(x)
#define x first
#define y second
#define mp make_pair

int n, m, k;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
bool inGrid(int x, int y) { return x >= 0 && x < n && y >= 0 && y < m; }

void solve() {
	cin >> n >> m >> k;

	int sx, sy;
	cin >> sx >> sy;
	int ex, ey;
	cin >> ex >> ey;

	sx--, sy--;
	ex--, ey--;

	vector<string> G(n);
	for (auto& i : G) cin >> i;

	vector<vector<int>> dist(n, vector<int>(m, -1));
	vector<vector<int>> distH(n, vector<int>(m, -1));
	vector<vector<int>> distV(n, vector<int>(m, -1));

	queue<pair<int, int>> q, qq;
	queue<array<int, 3>> q2, q3;
	q.push(mp(sx, sy));
	dist[sx][sy] = 0;

	int curD = 0;
	while (dist[ex][ey] == -1) {
		// cout << "GO :" << curD << endl;
		while (!q.empty()) {
			auto [a, b] = q.front();
			q.pop();
			distH[a][b] = k;
			distV[a][b] = k;
			// cout << a << ' ' << b << '\n';

			for (int d = 0; d < 4; d++) {
				int na = a + dx[d];
				int nb = b + dy[d];
				if (inGrid(na, nb) && dist[na][nb] == -1) {
					if (G[na][nb] == '.') {
						dist[na][nb] = curD;
						q.push(mp(na, nb));
					} else {
						dist[na][nb] = curD + 1;
						q2.push({k, na, nb});
						qq.push(mp(na, nb));
					}
				}
			}
		}

		while (!q2.empty()) {
			auto [d, a, b] = q2.front();
			q2.pop();
			if (distH[a][b] >= d) continue;

			if (dist[a][b] == -1) {
				dist[a][b] = curD + 1;
				q.push(mp(a, b));
			}

			distH[a][b] = d;
			q3.push({k, a, b});
			if (d > 1) {
				if (b > 0) q2.push({d - 1, a, b - 1});
				if (b + 1 < m) q2.push({d - 1, a, b + 1});
			}
		}

		while (!q3.empty()) {
			auto [d, a, b] = q3.front();
			q3.pop();
			if (distV[a][b] >= d) continue;
			distV[a][b] = d;

			if (dist[a][b] == -1) {
				dist[a][b] = curD + 1;
				q.push(mp(a, b));
			}

			if (d > 1) {
				if (a > 0) q3.push({d - 1, a - 1, b});
				if (a + 1 < n) q3.push({d - 1, a + 1, b});
			}
		}

		curD++;

		while (!qq.empty()) {
			q.push(qq.front());
			qq.pop();
		}
	}

	cout << dist[ex][ey] << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t = 1;
	// cin >> t;
	for (int i = 0; i < t; i++) { solve(); }
	return 0;
}