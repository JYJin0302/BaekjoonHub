#include <bits/stdc++.h>
using namespace std;

int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1, 0 };
int n, m, p;
priority_queue<tuple<int, int, int, int>> pq, tq;  // p, cnt, x, y, 

vector<string> grid;
vector<int> step;

bool inGrid(int x, int y) {
	return x >= 0 && x < n&& y >= 0 && y < m;
}

void bfs() {

	while (!pq.empty()) {

		int a, b, c, d;
		tie(a, d, b, c) = pq.top();
		pq.pop();

		a *= -1;
		d *= -1;

		if (step[a - 1] == d) {
			tq.push({ a*-1, 0, b, c });
			continue;
		}

		for (int i = 0; i < 4; i++) {
			int nb = b + dx[i];
			int nc = c + dy[i];

			if (inGrid(nb, nc) && grid[nb][nc] == '.') {
				grid[nb][nc] = '0' + a;
				pq.push({ a * -1, d*(-1)-1, nb, nc });
			}
		}
	}

	swap(pq, tq);
	if (pq.empty()) return;
	bfs();
}

int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);
	cin >> n >> m >> p;

	step = vector<int>(p);
	for (auto& i : step) cin >> i;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		grid.push_back(s);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (grid[i][j] != '.' && grid[i][j] != '#') {
				pq.push({ -1 * (grid[i][j] - '0'),0, i, j});
			}
		}
	}

	bfs();

	

	vector<int> ans(p+1);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (grid[i][j] >= '1' && grid[i][j] <= '9') {
				ans[grid[i][j] - '0']++;
			}
		}
	}
	for (int i = 1; i <= p; i++) {
		cout << ans[i] << ' ';
	}
}