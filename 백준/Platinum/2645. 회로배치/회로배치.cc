#include <bits/stdc++.h>
using namespace std;

int n;
int dx[] = { 0, -1, 0, 1 };
int dy[] = { 1, 0, -1, 0 };
bool inGrid(int x, int y) {
	return x >= 1 && x <= n && y >= 1 && y <= n;
}
int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);
	
	cin >> n;

	vector<vector<bool>> grid(n+1, vector<bool>(n+1));

	pair<int, int> s, d;
	cin >> s.first >> s.second;
	cin >> d.first >> d.second;

	int k;
	cin >> k;


	// initialize grid
	int t;
	cin >> t;

	while (t--) {

		int tt;
		cin >> tt;

		pair<int, int> pre;
		cin >> pre.first >> pre.second;

		grid[pre.first][pre.second] = 1;

		for (int i = 0; i < tt - 1; i++) {
			int a, b;
			cin >> a >> b;

			if (a == pre.first) {
				if (b > pre.second) {
					for (int k = pre.second + 1; k <= b; k++) grid[a][k] = 1;
				}
				else {
					for (int k = b; k < pre.second; k++) grid[a][k] = 1;
				}
			}
			else {
				if (a > pre.first) {
					for (int k = pre.first + 1; k <= a; k++) grid[k][b] = 1;
				}
				else {
					for (int k = a; k < pre.first; k++) grid[k][b] = 1;
				}
			}

			pre = { a, b };
		}
	}

	// find path
	vector<vector<int>> path(n + 1, vector<int>(n + 1, -1));
	int init = 1;
	if (grid[s.first][s.second]) init = k;

	priority_queue<tuple<int, int, int>> pq;  // cnt, x, y
	pq.push({ -init, s.first, s.second });

	while (!pq.empty()) {

		int a, b, c;
		tie(a, b, c) = pq.top();
		pq.pop();

		a *= -1;
		if (path[b][c] != -1) continue;
		path[b][c] = a;

		for (int i = 0; i < 4; i++) {
			int nb = b + dx[i];
			int nc = c + dy[i];

			if (inGrid(nb, nc) && path[nb][nc] == -1) {
				int na = a;
				if (grid[nb][nc]) na += k;
				else na += 1;
				pq.push({ -na, nb, nc });
			}
		}
	}

	// find ans
	// face -> 0: right, 1: up, 2: left, 3: down

	int x, y;
	tie(x, y) = d;

	vector<pair<int, int>> ans;

	int facechange = 0;
	int face = -1;
	while (!(x == s.first && y == s.second)) {

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			int dd = 1;
			if (grid[x][y]) dd = k;

			if (inGrid(nx, ny) && path[nx][ny] + dd == path[x][y]) {
				if (i != face) {
					face = i;
					facechange++;
					ans.push_back({ x, y });
				}
				x = nx, y = ny;
				break;
			}
		}
	}

	ans.push_back(s);
	reverse(ans.begin(), ans.end());

	cout << path[d.first][d.second] << '\n';
	cout << facechange + 1 << ' ';
	for (auto i : ans) cout << i.first << ' ' << i.second << ' ';
	cout << '\n';
}