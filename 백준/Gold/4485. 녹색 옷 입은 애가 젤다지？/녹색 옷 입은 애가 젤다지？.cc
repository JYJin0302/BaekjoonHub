#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000

vector<vector<int>> grid;
int n, a, b, c, x, y, cnt;
int step[4][2] = { {-1, 0}, {1, 0}, {0, 1}, {0, -1} };
bool outofgrid(int r, int c) {
	return (r < 0 || r >= n) || (c < 0 || c >= n);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cnt = 1;
	cin >> n;
	while (n != 0) {
		grid = vector<vector<int>>(n, vector<int>(n));
		for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
			cin >> grid[i][j];
		}
		map<pair<int, int>, bool > check;
		vector<vector<int>> path(n, vector<int>(n, INF));

		priority_queue<tuple<int, int, int >> pq;
		pq.push({ 0, 0, 0 });
		path[0][0] = grid[0][0];
		while (!pq.empty()) {
			tie(a, b, c) = pq.top();
			pq.pop();
			if (check[{b, c }] == 1) continue;

			check[{b, c}] = 1;
			for (int i = 0; i < 4; i++) {
				x = b + step[i][0];
				y = c + step[i][1];
				if (!outofgrid(x, y) && !check[{x, y}]) {
					if (path[x][y] > path[b][c] + grid[x][y]) {
						path[x][y] = path[b][c] + grid[x][y];
						pq.push({ -path[x][y], x, y });
					}
				}
			}

		}

		cout << "Problem " << cnt << ": " << path[n - 1][n - 1] << '\n';

		cnt++;
		cin >> n;
	}

}