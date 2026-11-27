#include <bits/stdc++.h>
using namespace std;

int N, M;

// 0-9 : 0-9, 10-35: A-Z, 36-61: a-z
int adj[62][62];
bool isin[62];
bool impo = 0;

int ctoi(char c) {
	if (c >= '0' && c <= '9') return c - '0';

	if (c >= 'A' && c <= 'Z') return 10 + c - 'A';

	return 36 + c - 'a';
}
char itoc(int x) {

	if (x >= 0 && x <= 9) return '0' + x;

	if (x >= 10 && x <= 35) return x - 10 + 'A';

	return x - 36 + 'a';
}

vector<string> grid;

void set_topo(int x) {

	int u, l, r, d, cnt = 0;

	// get range
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (ctoi(grid[i][j]) == x) {

				if (cnt == 0) {
					u = i, d = i;
					l = j, r = j;
					cnt++;
				}
				else {
					u = min(u, i), d = max(d, i);
					l = min(l, j), r = max(r, j);
				}
			}
		}
	}

	// get edge
	for (int i = u; i <= d; i++) {
		for (int j = l; j <= r; j++) {
			if (grid[i][j] == '.') {
				impo = 1;
				return;
			}
			int k = ctoi(grid[i][j]);
			adj[x][k] = 1;
		}
	}
	adj[x][x] = 0;

}

int main() {

	cin >> N >> M;
	grid = vector<string>(N);
	for (auto& i : grid) cin >> i;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (grid[i][j] == '.') continue;

			int k = ctoi(grid[i][j]);
			isin[k] = 1;
		}
	}

	for (int i = 0; i < 62; i++) {
		if (!isin[i]) continue;
		set_topo(i);
	}

	if (impo) {
		cout << -1;
		return 0;
	}

	vector<int> topo(62);
	for (int i = 0; i < 62; i++) {
		for (int j = 0; j < 62; j++) {
			topo[i] += adj[j][i];
		}
	}

	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < 62; i++) {
		if (isin[i] && topo[i] == 0) {
			pq.push(i);
		}
	}

	string ans;
	while (!pq.empty()) {

		int a = pq.top();
		pq.pop();

		ans += itoc(a);

		for (int i = 0; i < 62; i++) {
			if (adj[a][i] == 1) {
				topo[i]--;
				if (topo[i] == 0) pq.push(i);
			}
		}
	}

	for (int i = 0; i < 62; i++) {
		if (isin[i] && topo[i] != 0) {

			cout << -1;
			return 0;
		}
	}

	cout << ans;

}