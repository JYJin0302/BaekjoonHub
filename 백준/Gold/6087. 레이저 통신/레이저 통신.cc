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

	cin >> w >> h;

	vector<string> grid;

	for (int i = 0; i < h; i++) {
		string s;
		cin >> s;
		grid.push_back(s);
	}

	int lx, ly;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (grid[i][j] == 'C') lx = i, ly = j;
		}
	}


	queue<tuple<int, int, int, bool>>q; // 거울 개수, x, y, 0: 세로, 1: 가로

	vector<vector<bool>> check(h, vector<bool>(w));
	check[lx][ly] = 1;
	
	for (int i = 0; i < 4; i++) {
		int tx = lx;
		int ty = ly;
		while (1) {
			tx += dx[i];
			ty += dy[i];

			if (inGrid(tx, ty) && grid[tx][ty] != '*') {
				check[tx][ty] = 1;
				q.push({ 0, tx,ty, i % 2 });
			}
			else break;
		}
	}

	while(!q.empty()) {
		int a, b, c, d;
		tie(a, b, c, d) = q.front();
		q.pop();
		d ^= 1;

		if (grid[b][c] == 'C') {
			cout << a;
			return 0;
		}

		for (int i = 0; i < 2; i++) {

			int tb = b;
			int tc = c;

			while (1) {
				tb += dx[i * 2 + d];
				tc += dy[i * 2 + d];

				if (inGrid(tb, tc) && grid[tb][tc] != '*') {
					if (!check[tb][tc]) {
						check[tb][tc] = 1;
						q.push({ a+1, tb,tc, d });
					}
				}
				else break;
			}
		}
	}

}