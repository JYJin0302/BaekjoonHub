#include <bits/stdc++.h>
using namespace std;

int n, m, ice = 0, a, b, c, d;
int grid[300][300];
vector<vector<bool>> check;
queue<pair<int, int>> q;

bool inGrid(int x, int y) {
	return (x >= 0 && x < n) && (y >= 0 && y < m);
}

int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };

int bfs() {
	int temp = 0;
	while (!q.empty()) {
		tie(a, b) = q.front();
		q.pop();
		temp++;
		for (int i = 0; i < 4; i++) {
			c = a + dx[i];
			d = b + dy[i];
			if (inGrid(c, d) && !check[c][d] && grid[c][d] != 0) {
				check[c][d] = 1;
				q.push({ c, d });
			}
		}
	}
	return temp;
}


int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);
	
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> grid[i][j];
			if (grid[i][j] != 0) ice++;
		}
	}
	vector<tuple<int, int, int>> differ;

	int year = 0;
	while (1) {
		year++;
		differ.clear();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (grid[i][j] != 0) {
					int cnt = 0;
					for (int k = 0; k < 4; k++) {
						a = i + dx[k];
						b = j + dy[k];
						if (inGrid(a, b) && grid[a][b] == 0) {
							cnt++;
						}
					}

					differ.push_back({ i, j, cnt });
				}
			}
		}

		for (auto i : differ) {
			tie(a, b, c) = i;
			grid[a][b] = max(0, grid[a][b] - c);
			if (grid[a][b] == 0) ice--;
		}

		check = vector<vector<bool>>(n, vector<bool>(m));
		bool nothing = true;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (grid[i][j] == 0) continue;
				nothing = false;
				check[i][j] = 1;
				q.push({ i, j });
				if (bfs() != ice) {
					cout << year;
					return 0;
				}
				break;
			}
			if (!nothing) break;
		}
		if (nothing) break;
	}

	cout << 0;
}