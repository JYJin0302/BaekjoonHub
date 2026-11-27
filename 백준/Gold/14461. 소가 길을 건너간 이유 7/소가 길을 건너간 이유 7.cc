#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int dx[] = { 0, -1, 0, 1 };
int dy[] = { 1, 0, -1, 0 };
int n, t;
bool inGrid(int x, int y) {
	return x >= 0 && x < n&& y >= 0 && y < n;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> t;

	vector<vector<int>>grid(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> grid[i][j];
		}
	}

	ll path[100][100][3];
	memset(path, -1, sizeof(path));

	priority_queue<tuple<ll, ll, ll, ll>> pq;  // time, cnt, x, y


	ll ans = -1;

	pq.push({ 0, 0, 0, 0 });
	while (!pq.empty()) {

		ll a, b, c, d;
		tie(a, b, c, d) = pq.top();
		pq.pop();

		a *= -1;
		if (path[c][d][b] != -1) continue;
		path[c][d][b] = a;
		if (c == n - 1 && d == n - 1) {
			ans = a;
			break;
		}

		for (int i = 0; i < 4; i++) {

			ll nc = c + dx[i];
			ll nd = d + dy[i];

			if (inGrid(nc, nd)) {
				ll na = a + t;
				if (b == 2) na += grid[nc][nd];
				ll nb = (b + 1) % 3;

				if (path[nc][nd][nb] == -1) pq.push({ -na, nb, nc,nd });
			}
		}
	}

	cout << ans;

}