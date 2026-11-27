#include <bits/stdc++.h>
using ll = long long;
using namespace std;

#define INF 100000000
#define pb push_back
#define all(x) (x).begin(),(x).end()

int dx[] = { 0, -1, 0, 1 };
int dy[] = { 1, 0, -1, 0 };

int n, m;

int visit1[102][102];
int visit2[102][102];
int visit3[102][102];

bool inGrid(int x, int y) {
	return x >= 0 && x <= n + 1 && y >= 0 && y <= m + 1;
}

void solve() {

	cin >> n >> m;

	vector<string> grid(n + 2);
	grid[0] = string(m + 2, '.');
	grid[n+1] = string(m + 2, '.');

	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		grid[i] = '.' + s + '.';
	}

	int cnt = 1;
	pair<int, int> p1, p2;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (grid[i][j] == '$') {
				if (cnt == 1) p1 = { i, j };
				else p2 = { i, j };
				cnt++;
			}
		}
	}

	memset(visit1, -1, sizeof(visit1));
	memset(visit2, -1, sizeof(visit2));
	memset(visit3, -1, sizeof(visit3));

	deque<tuple<int, int, int>> dq; // cnt, x, y;
	dq.push_back({ 0, 0, 0 });
	visit1[0][0] = 0;
	while (!dq.empty()) {

		int c, x, y;
		tie(c, x, y) = dq.front();
		dq.pop_front();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (inGrid(nx, ny) && grid[nx][ny] != '*' && visit1[nx][ny] == -1) {
				if (grid[nx][ny] == '#') {
					visit1[nx][ny] = c + 1;
					dq.push_back({ c + 1, nx, ny });
				}
				else {
					visit1[nx][ny] = c;
					dq.push_front({ c, nx, ny });
				}
			}
		}
	}

	int x, y;
	tie(x, y) = p1;
	dq.push_back({ 0, x, y });
	visit2[x][y] = 0;
	while (!dq.empty()) {

		int c, x, y;
		tie(c, x, y) = dq.front();
		dq.pop_front();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (inGrid(nx, ny) && grid[nx][ny] != '*' && visit2[nx][ny] == -1) {
				if (grid[nx][ny] == '#') {
					visit2[nx][ny] = c + 1;
					dq.push_back({ c + 1, nx, ny });
				}
				else {
					visit2[nx][ny] = c;
					dq.push_front({ c, nx, ny });
				}
			}
		}
	}


	tie(x, y) = p2;
	dq.push_back({ 0, x, y });
	visit3[x][y] = 0;
	while (!dq.empty()) {

		int c, x, y;
		tie(c, x, y) = dq.front();
		dq.pop_front();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (inGrid(nx, ny) && grid[nx][ny] != '*' && visit3[nx][ny] == -1) {
				if (grid[nx][ny] == '#') {
					visit3[nx][ny] = c + 1;
					dq.push_back({ c + 1, nx, ny });
				}
				else {
					visit3[nx][ny] = c;
					dq.push_front({ c, nx, ny });
				}
			}
		}
	}

	int ans = 10001;
	for (int i = 0; i <= n + 1; i++) {
		for (int j = 0; j <= m + 1; j++) {
			if (visit1[i][j] != -1 && visit2[i][j] != -1 && visit3[i][j] != -1) {
				ans = min(ans, visit1[i][j] + visit2[i][j] + visit3[i][j] - 2 * (grid[i][j] == '#'));
			}
		}
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T = 1;
	cin >> T;

	while (T--) {
		solve();
	}
}