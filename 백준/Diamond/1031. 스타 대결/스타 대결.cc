#include <bits/stdc++.h>
using namespace std;

// source: 0, A: 1 - n, B: 51 - 50 + m, sink: 101
int n, m;
int f[102][102];
int c[102][102];

void fix_path(int x, int y) {

	pair<int, int> from[102][102];

	for (int i = 1; i <= n; i++) {
		for (int j = 51; j <= 50 + m; j++) {
			from[i][j] = { -1, -1 };
		}
	}

	queue<tuple<int, int, int>> q;
	q.push({ x, y, 0 });
	while (!q.empty()) {

		int a, b, t;
		tie(a, b, t) = q.front();
		q.pop();

		if (t == 0) {

			int i = a;
			for (int j = 51; j <= 50 + m; j++) {
				if ((i > x || (i == x && j >= y)) && from[i][j].first == -1 && f[i][j] == t) {
					from[i][j] = { a, b };
					q.push({ i, j, 1 - t });
				}
			}
		}
		else {

			int j = b;
			for (int i = 1; i <= n; i++) {
				if ((i > x || (i == x && j >= y)) && from[i][j].first == -1 && f[i][j] == t) {
					from[i][j] = { a, b };
					q.push({ i, j, 1 - t });
				}
			}
		}
	}

	if (from[x][y].first != -1) {

		int a, b;
		tie(a, b) = { x, y };

		while (1) {
			f[a][b] = 1 - f[a][b];
			tie(a, b) = from[a][b];

			if (a == x && b == y) break;
		}
	}
}

int main() {

	
	cin >> n >> m;

	vector<int> A(n), B(m);
	for (auto& i : A) cin >> i;
	for (auto& i : B) cin >> i;

	int totA = 0, totB = 0;
	for (int i : A) totA += i;
	for (int i : B) totB += i;

	if (totA != totB) {
		cout << -1;
		return 0;
	}

	// 용량 설정
	for (int i = 0; i < n; i++) {
		c[0][i + 1] = A[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			c[i + 1][j + 51] = 1;
		}
	}
	for (int j = 0; j < m; j++) {
		c[j + 51][101] = B[j];
	}

	int conn = 0;
	while (1) {

		vector<int> from(102, -1);

		queue<int> q;
		q.push(0);
		from[0] = 0;

		while (!q.empty()) {

			int a = q.front();
			q.pop();

			for (int i = 1; i <= 101; i++) {
				if (from[i] == -1 && c[a][i] - f[a][i] > 0) {
					from[i] = a;
					q.push(i);
				}
			}
		}

		if (from[101] == -1) break;

		conn++;
		int x = 101;
		while (x != 0) {
			f[from[x]][x]++;
			f[x][from[x]]--;
			x = from[x];
		}
	}


	if (conn != totA) {
		cout << -1;
		return 0;
	}


	// 경로 조정

	for (int i = 1; i <= n; i++) {
		for (int j = 51; j <= 50 + m; j++) {
			if (f[i][j] == 1) {
				// try 경로 조정
				fix_path(i, j);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 51; j <= 50 + m; j++) {
			cout << f[i][j];
		}
		cout << '\n';
	}


}