#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n, m, t;
int grid[50][50];
int diff[50][50];

int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };

pair<int, int> u, d;

bool inGrid(int x, int y) {
	return x >= 0 && x < n&& y >= 0 && y < m;
}

void spread() {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (grid[i][j] <= 0) continue;

			int b = grid[i][j] / 5;
			for (int k = 0; k < 4; k++) {
				int ni = i + dx[k];
				int nj = j + dy[k];
				if (inGrid(ni, nj) && grid[ni][nj] != -1) {
					diff[ni][nj] += b;
					diff[i][j] -= b;
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			grid[i][j] += diff[i][j];
			diff[i][j] = 0;
		}
	}

}

void flow() {

	int x, y;
	// up
	tie(x, y) = u;

	for (int i = y - 2; i >= 0; i--) {
		grid[x][i + 1] = grid[x][i];
	}
	if (y != 0) grid[x][0] = grid[x - 1][0];

	for (int i = x - 2; i >= 0; i--) {
		grid[i + 1][0] = grid[i][0];
	}

	for (int i = 1; i < m; i++) {
		grid[0][i - 1] = grid[0][i];
	}

	for (int i = 1; i <= x; i++) {
		grid[i - 1][m - 1] = grid[i][m - 1];
	}

	if (y == m - 1) grid[x - 1][y] = 0;
	else {
		for (int i = m - 2; i > y; i--) {
			grid[x][i+1] = grid[x][i];
		}
		grid[x][y + 1] = 0;
	}

	// down
	tie(x, y) = d;

	for (int i = y - 2; i >= 0; i--) {
		grid[x][i + 1] = grid[x][i];
	}
	if (y != 0) grid[x][0] = grid[x + 1][0];

	for (int i = x + 2; i < n; i++) {
		grid[i - 1][0] = grid[i][0];
	}

	for (int i = 1; i < m; i++) {
		grid[n - 1][i - 1] = grid[n - 1][i];
	}

	for (int i = n - 1; i > x; i--) {
		grid[i][m - 1] = grid[i - 1][m - 1];
	}

	if (y == m - 1) grid[x + 1][y] = 0;
	else {
		for (int i = m - 2; i > y; i--) {
			grid[x][i + 1] = grid[x][i];
		}
		grid[x][y + 1] = 0;
	}
}
void display() {

	cout << "TEST: \n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << grid[i][j] << ' ';
		}
		cout << '\n';
	}
}

int main() {

	cin >> n >> m >> t;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> grid[i][j];
			if (grid[i][j] == -1) {
				if (cnt == 0) u = { i, j };
				else d = { i, j };
				cnt++;
			}
		}
	}

	while (t--) {
		spread();
		flow();
	}

	ll ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			ans += grid[i][j];
		}
	}
	cout << ans + 2;
}