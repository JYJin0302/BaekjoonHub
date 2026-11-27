#include <bits/stdc++.h>
using namespace std;

int h, w;
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, -1, 0, 1 };
bool path[20][20][1 << 10];

bool inGrid(int x, int y) {
	return x >= 0 && x < h&& y >= 0 && y < w;
}

int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);
	
	cin >> w >> h;
	while (!(h == 0 && w == 0)) {

		memset(path, 0, sizeof(path));

		vector<string> grid;
		for (int i = 0; i < h; i++) {
			string s;
			cin >> s;
			grid.push_back(s);
		}

		map<pair<int, int>, int> ptoi;
		map<int, pair<int, int>> itop;

		int x = -1, y = -1;
		int cnt = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (grid[i][j] == '*') {
					ptoi[{i, j}] = cnt;
					itop[cnt] = { i , j };
					cnt++;
				}
				if (grid[i][j] == 'o') x = i, y = j;
			}
		}

		int target = (1 << cnt) - 1;
		bool ok = false;

		queue<tuple<int, int, int, int>> pq;  // 이동거리, x, y, 청소
		pq.push({ 0, x, y, 0 });
		path[x][y][0] = 1;
		while (!pq.empty()) {
			int a, b, c, d;
			tie(a, b, c, d) = pq.front();
			pq.pop();

			if (d == target) {
				ok = true;
				cout << a << '\n';
				break;
			}

			for (int i = 0; i < 4; i++) {

				int nb = b + dx[i];
				int nc = c + dy[i];

				if (inGrid(nb, nc) && grid[nb][nc] != 'x') {
					int td = d;
					if (grid[nb][nc] == '*') td |= (1 << ptoi[{ nb, nc }]);

					if (!path[nb][nc][td]) {
						path[nb][nc][td] = 1;
						pq.push({ a + 1, nb, nc, td });
					}
				}
			}

		}
		if (!ok) cout << -1 << '\n';

		cin >> w >> h;
	}
}