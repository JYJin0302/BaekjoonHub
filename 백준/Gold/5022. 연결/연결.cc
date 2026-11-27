#include <bits/stdc++.h>
using namespace std;

int n, m, dist = -1;
int path[101][101];
int dx[] = { 0, -1, 0, 1 };
int dy[] = { 1, 0, -1, 0 };

bool inGrid(int x, int y) {
	return x >= 0 && x <= n && y >= 0 && y <= m;
}

void emptyqueue(queue<pair<int, int>>& q1) {
	queue<pair<int, int>> temp;
	swap(q1, temp);
}

void connect(pair<int, int> s, pair<int, int> d) {
	int x, y;
	tie(x, y) = s;
	path[x][y] = 0;
	queue<pair<int, int>> q;

	q.push({ x, y });
	while (!q.empty()) {

		int a, b;
		tie(a, b) = q.front();
		q.pop();

		if (a == d.first && b == d.second) break;

		for (int i = 0; i < 4; i++) {
			int na = a + dx[i];
			int nb = b + dy[i];
			if (inGrid(na, nb) && path[na][nb] == -1) {
				path[na][nb] = path[a][b] + 1;
				q.push({ na, nb });
			}
		}
	}

	dist = path[d.first][d.second];
	if (dist == -1) return;

	emptyqueue(q);
	q.push({ d.first, d.second });
	while (!q.empty()) {

		int a, b;
		tie(a, b) = q.front();
		q.pop();

		if (a == s.first && b == s.second) break;

		for (int i = 0; i < 4; i++) {
			int na = a + dx[i];
			int nb = b + dy[i];

			if (inGrid(na, nb) && path[na][nb] == path[a][b] - 1) {
				path[a][b] = 100000;
				q.push({ na, nb });
				break;
			}
		}
	}
	path[s.first][s.second] = 100000;

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			if (path[i][j] == 100000) path[i][j] = -2;
			else path[i][j] = -1;
		}
	}

}

int main() {

	
	cin >> n >> m;

	pair<int, int> a1, a2, b1, b2;

	cin >> a1.first >> a1.second;
	cin >> a2.first >> a2.second;
	cin >> b1.first >> b1.second;
	cin >> b2.first >> b2.second;

	queue<pair<int, int>> q;

	int ans = -1;
	// A -> B
	int tans = -1;
	memset(path, -1, sizeof(path));
	
	path[b1.first][b1.second] = -2;
	path[b2.first][b2.second] = -2;
	connect(a1, a2);

	if (dist != -1) {
		tans = dist;

		connect(b1, b2);

		if (dist != -1) {
			tans += dist;
			if (ans == -1) ans = tans;
			else ans = min(ans, tans);
		}
	}

	tans = -1;
	memset(path, -1, sizeof(path));

	swap(a1, b1);
	swap(a2, b2);

	path[b1.first][b1.second] = -2;
	path[b2.first][b2.second] = -2;
	connect(a1, a2);

	if (dist != -1) {
		tans = dist;

		connect(b1, b2);

		if (dist != -1) {
			tans += dist;
			if (ans == -1) ans = tans;
			else ans = min(ans, tans);
		}
	}
	
	if (ans == -1) cout << "IMPOSSIBLE\n";
	else cout << ans;

}