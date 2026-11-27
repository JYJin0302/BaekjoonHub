#include <bits/stdc++.h>
using namespace std;


int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, -1, 0, 1 };

int m, n;
vector<string> grid;

bool inGrid(int x, int y) {
	return x >= 0 && x < n&& y >= 0 && y < m;
}

int main() {

	
	cin >> m >> n;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		grid.push_back(s);
	}

	vector<vector<bool>> check(n, vector<bool>(m));

	priority_queue<tuple<int, int, int>> pq;
	pq.push({ 0, 0, 0 });
	check[0][0] = 1;

	while (!pq.empty()) {
		int a, b, c;
		tie(a, b, c) = pq.top();
		pq.pop();

		if (b == n - 1 && c == m - 1) {
			cout << a * -1;
			return 0;
		}

		for (int i = 0; i < 4; i++) {

			int nb = b + dx[i];
			int nc = c + dy[i];

			if (inGrid(nb, nc) && !check[nb][nc]) {
				check[nb][nc] = 1;
				if (grid[nb][nc] == '1') {
					pq.push({ a - 1, nb, nc });
				}
				else pq.push({ a, nb, nc });
			}

		}
	}
}