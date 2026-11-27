#include <bits/stdc++.h>
using namespace std;

int n, m, cnt = 0, sx, sy;
int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };
int path[50][50][1 << 6];
bool found;

vector<string> grid;
queue<tuple<int, int, int>> q;  // 좌표 x, y, 가지고 있는 열쇠
queue<tuple<int, int, int>> tq;

bool valid(int x, int y) {
	return x >= 0 && x < n&& y >= 0 && y < m && grid[x][y] != '#';
}

void bfs() {

	while (!q.empty()) {
		int a, b, c;
		tie(a, b, c) = q.front();
		q.pop();
		
		if (grid[a][b] == '1') {
			found = true;
			return;
		}

		int x, y;
		for (int i = 0; i < 4; i++) {
			x = a + dx[i];
			y = b + dy[i];
			if (valid(x, y)) {
				if ((x == sx && y == sy && c == 0) || path[x][y][c] != 0) continue;

				if (grid[x][y] >= 'A' && grid[x][y] <= 'F') {
					if (c & (1 << (grid[x][y] - 'A'))) {
						path[x][y][c] = cnt;
						tq.push({ x, y, c });
					}
				}

				else if (grid[x][y] >= 'a' && grid[x][y] <= 'f') {
					int tc = c | (1 << (grid[x][y] - 'a'));
					path[x][y][tc] = cnt;
					tq.push({ x, y, tc });
				}

				else {
					path[x][y][c] = cnt;
					tq.push({ x, y, c });
				}
			}
		}
	}

	swap(q, tq);
	if (q.empty()) return;
	cnt++;
	bfs();
}

int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		grid.push_back(s);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (grid[i][j] == '0') {
				tie(sx, sy) = { i, j };
				q.push({ i, j, 0 });
			}
		}
	}

	found = false;
	bfs();

	if (!found) cout << -1;
	else cout << cnt;
}