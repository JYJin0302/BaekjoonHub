#include <iostream>
#include <assert.h>
using namespace std;

int n, m;
int grid[2020][2020];
int cost[2020][2020];
int vs[2020][2020];

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };
// u, r, d, l

int chartoidx(char c) {
	switch (c) {
	case 'U':
		return 0;
	case 'R':
		return 1;
	case 'D':
		return 2;
	case 'L':
		return 3;
	default:
		assert(0);
		return -1;
	}
}

bool inGrid(int x, int y) {
	return x >= 0 && x < n&& y >= 0 && y < m;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char c;
			cin >> c;
			grid[i][j] = chartoidx(c);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> cost[i][j];
		}
	}

	// ----- input end -----

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (vs[i][j] == 2) continue;
			assert(vs[i][j] == 0);

			int currX = i, currY = j;
			while (inGrid(currX, currY) && vs[currX][currY] == 0) {
				vs[currX][currY] = 1;
                int ix = grid[currX][currY];
				currX += dx[ix];
				currY += dy[ix];
			}

			if (inGrid(currX, currY) && vs[currX][currY] == 1) {
				// cycle found
				int ansAdd = 505;
				while (inGrid(currX, currY) && vs[currX][currY] != 2) {
					vs[currX][currY] = 2;
					ansAdd = min(ansAdd, cost[currX][currY]);
					int ix = grid[currX][currY];
				    currX += dx[ix];
				    currY += dy[ix];
				}
				ans += ansAdd;
			}
			currX = i, currY = j;
			while (inGrid(currX, currY) && vs[currX][currY] != 2) {
				vs[currX][currY] = 2;
				int ix = grid[currX][currY];
				currX += dx[ix];
				currY += dy[ix];
			}
		}
	}
	cout << ans;
	return 0;
}