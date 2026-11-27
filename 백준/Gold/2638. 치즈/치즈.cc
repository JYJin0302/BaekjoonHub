#include <bits/stdc++.h>
using namespace std;

int n, m;
int grid[100][100];
int cnt[100][100];
bool check[100][100];

int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };

bool inGrid(int x, int y) {
	return (x >= 0 && x < n&& y >= 0 && y < m);
}

int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> grid[i][j];
		}
	}

	int ans = 0;
	priority_queue<tuple<int, int, int>> pq; // cnt, i, j
	pq.push({ 0, 0, 0 });
	check[0][0] = 1;
	while (!pq.empty()) {
		int a, x, y, nx, ny;
		tie(a, x, y) = pq.top();
		pq.pop();
		a *= -1;

		ans = max(ans, a);
		for (int i = 0; i < 4; i++) {
			nx = x + dx[i];
			ny = y + dy[i];
			if (inGrid(nx, ny) && !check[nx][ny]) {
				if (grid[nx][ny] == 1) {
					cnt[nx][ny]++;
					if (cnt[nx][ny] == 2) {
						pq.push({ -a - 1, nx, ny });
						check[nx][ny] = 1;
					}
				}
				else {
					check[nx][ny] = 1;
					pq.push({ -a, nx, ny });
				}
			}
		}

	}
	cout << ans;
}