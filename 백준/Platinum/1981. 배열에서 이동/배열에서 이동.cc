#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int A[101][101];
bool v[101][101];

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

int n;
bool inGrid(int x, int y) {
	return x >= 0 && x < n&& y >= 0 && y < n;
}


void solve() {

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> A[i][j];
		}
	}

	int ans = 4000;

	priority_queue<tuple<int, int, int>> pq;
	for (int up = A[0][0]; up <= 200; up++) {

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				v[i][j] = 0;
			}
		}

		int mv = A[0][0];

		pq.push({ A[0][0], 0, 0 });
		while (!pq.empty()) {

			int a, x, y;
			tie(a, x, y) = pq.top();
			pq.pop();

			if (a > up) break;
			mv = min(mv, a);
			if (x == n - 1 && y == n - 1) break;

			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (inGrid(nx, ny) && !v[nx][ny] && A[nx][ny] <= up) {
					v[nx][ny] = 1;
					pq.push({ A[nx][ny], nx, ny });
				}
			}

		}
		while (!pq.empty()) pq.pop();

		if (v[n - 1][n - 1]) {
			ans = min(ans, up - mv);
		}
	}
	cout << ans;

}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}

}