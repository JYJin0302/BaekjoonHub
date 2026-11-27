#include <bits/stdc++.h>
using namespace std;

int n;
int grid[500][500];
int dp[500][500];

int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };

bool inGrid(int x, int y) {
	return x >= 0 && x < n&& y >= 0 && y < n;
}

void dfs(int x, int y) {

	if (dp[x][y] != 0) return;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (inGrid(nx, ny) && grid[nx][ny] > grid[x][y]) {
			dfs(nx, ny);
			dp[x][y] = max(dp[x][y], dp[nx][ny]);
		}
	}
	dp[x][y]+= 1;
}


int main() {

	ios::sync_with_stdio(false);
    cin.tie(nullptr);
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> grid[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (dp[i][j] == 0) {
				dfs(i, j);
			}
		}
	}
	int ans = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ans = max(ans, dp[i][j]);
		}
	}

	cout << ans;
}