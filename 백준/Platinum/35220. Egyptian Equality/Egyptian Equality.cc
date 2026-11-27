#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

int n, m;
char G[303][707];
char tmp[303][707];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
bool inGrid(int x, int y) { return x >= 0 && x < n && y >= 0 && y < m; }
void setup() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			tmp[i][j] = G[i][j];
			if (tmp[i][j] != '#') tmp[i][j] = 'B';
		}
	}
}

void solve() {
	cin >> n;
	m = n * 2 - 1;

	int tot = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> G[i][j];
			if (G[i][j] == 'C') tot++;
		}
	}

	if (tot & 1) {
		cout << "impossible\n";
		return;
	}
	tot >>= 1;
	// top to bottom
	queue<pair<int, int>> q;
	setup();

	int cnt = 0;
	q.push(mp(0, n - 1));
	while (!q.empty()) {
		auto [a, b] = q.front();
		q.pop();
		if (tmp[a][b] == 'A') continue;
		tmp[a][b] = 'A';
		if (G[a][b] == 'C') cnt++;
		if (cnt == tot) break;

		for (int d = 0; d < 4; d++) {
			int na = a + dx[d];
			int nb = b + dy[d];
			if (inGrid(na, nb) && G[na][nb] != '#' && tmp[na][nb] == 'B' && na < n - 1) { q.push(mp(na, nb)); }
		}
	}

	if (cnt == tot) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) { cout << tmp[i][j]; }
			cout << '\n';
		}
		return;
	}

	// left
	cnt = 0;
	setup();
	while (!q.empty()) q.pop();
	q.push(mp(n - 1, 0));
	while (!q.empty()) {
		auto [a, b] = q.front();
		q.pop();
		if (tmp[a][b] == 'A') continue;
		tmp[a][b] = 'A';
		if (G[a][b] == 'C') cnt++;
		if (cnt == tot) break;

		for (int d = 0; d < 4; d++) {
			int na = a + dx[d];
			int nb = b + dy[d];
			if (inGrid(na, nb) && G[na][nb] != '#' && tmp[na][nb] == 'B' && nb - na < n - 2) { q.push(mp(na, nb)); }
		}
	}

	if (cnt == tot) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) { cout << tmp[i][j]; }
			cout << '\n';
		}
		return;
	}

	// right
	cnt = 0;
	setup();
	while (!q.empty()) q.pop();
	q.push(mp(n - 1, m - 1));
	while (!q.empty()) {
		auto [a, b] = q.front();
		q.pop();
		if (tmp[a][b] == 'A') continue;
		tmp[a][b] = 'A';
		if (G[a][b] == 'C') cnt++;
		if (cnt == tot) break;

		for (int d = 0; d < 4; d++) {
			int na = a + dx[d];
			int nb = b + dy[d];
			if (inGrid(na, nb) && G[na][nb] != '#' && tmp[na][nb] == 'B' && nb + na > n) { q.push(mp(na, nb)); }
		}
	}

	if (cnt == tot) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) { cout << tmp[i][j]; }
			cout << '\n';
		}
		return;
	}

	cout << "impossible\n";
}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 1;
	// cin >> t;
	for (int i = 1; i <= t; i++) {
		// cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}