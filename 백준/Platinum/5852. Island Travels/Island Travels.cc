#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000
int n, m;
int cnt = 0;
vector<string> grid;
vector<vector<int>> island;
int dx[] = { 0, 0, -1, 1 };
int dy[] = { 1, -1, 0, 0 };
bool inGrid(int x, int y) {
	return x >= 0 && x < n&& y >= 0 && y < m;
}

void bfs1(int x, int y) {

	queue<pair<int, int>> q;
	q.push({ x, y });
	while (!q.empty()) {

		int a, b;
		tie(a, b) = q.front();
		q.pop();

		island[a][b] = cnt;
		for (int i = 0; i < 4; i++) {
			int na = a + dx[i];
			int nb = b + dy[i];

			if (inGrid(na, nb) && grid[na][nb] == 'X' && island[na][nb] == 0) {
				q.push({ na, nb });
			}
		}
	}
}

vector<vector<bool>> visited;
vector<tuple<int, int, int>> edge;  // 이동거리, 이어진 두 섬

void bfs2(int x, int y, int is) {
	vector<pair<int, int>> ss;

	priority_queue<tuple<int ,int, int>> q;
	q.push({0, x, y });
	visited[x][y] = 1;
	while (!q.empty()) {

		int a, b, c;
		tie(c, a, b) = q.top();
		q.pop();
		c *= -1;

		for (int i = 0; i < 4; i++) {
			int na = a + dx[i];
			int nb = b + dy[i];

			if (inGrid(na, nb) && !visited[na][nb]) {

				if (grid[na][nb] == 'X' && island[na][nb] != is) {
					edge.push_back({ c, is, island[na][nb] });
				}
				else if (grid[na][nb] != '.') {
					visited[na][nb] = 1;
					q.push({ -(c + (grid[na][nb] == 'S')), na, nb });
					if (grid[na][nb] == 'S') ss.push_back({ na ,nb });
				}
			}
		}
	}

	// 방문한 S 초기화
	for (auto i : ss) {
		int a, b;
		tie(a, b) = i;
		visited[a][b] = 0;
	}
}

vector<vector<int>> path, dp;
vector<vector<bool>> vvisited;
void solve(int v, int pv) {
	
	
	if (dp[v][pv] != INF) return;


	for (int i = 0; i < cnt; i++) {
		if ((pv & (1 << i)) && i != v) {

			if (!vvisited[i][pv ^ (1 << v)]) {
				vvisited[i][pv ^ (1 << v)] = 1;
				solve(i, pv ^ (1 << v));
			}
			dp[v][pv] = min(dp[v][pv], dp[i][pv ^ (1 << v)] + path[i][v]);
		}
	}
	for (int i = 0; i < cnt; i++) {
		if ((pv & (1 << i)) && i != v) {

			if (!vvisited[i][pv]) {
				vvisited[i][pv] = 1;
				solve(i, pv);
			}
			dp[v][pv] = min(dp[v][pv], dp[i][pv] + path[i][v]);
		}
	}
}

int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		grid.push_back(s);
	}

	island = vector<vector<int>>(n, vector<int>(m));
	visited = vector<vector<bool>>(n, vector<bool>(m));
	
	// 섬 정의
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (grid[i][j] == 'X' && island[i][j] == 0) {
				cnt++;
				bfs1(i, j);
			}
		}
	}

	// 간선 정의
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (grid[i][j] == 'X' && !visited[i][j]) {
				bfs2(i, j, island[i][j]);
			}
		}
	}
	 path = vector<vector<int>>(cnt, vector<int>(cnt, INF));
	for (auto i : edge) {
		int a, b, c;
		tie(a, b, c) = i;
		path[b-1][c-1] = min(path[b-1][c-1], a);
		path[c-1][b-1] = min(path[c-1][b-1], a);
	}
	dp = vector<vector<int>>(15, vector<int>(1 << 15, INF));
	vvisited = vector<vector<bool>>(15, vector<bool>(1 << 15));
	for (int i = 0; i < cnt; i++) {
		dp[i][1 << i] = 0;
	}

	int ans = INF;

	for (int i = 0; i < cnt; i++) {
		if (!vvisited[i][(1 << cnt) - 1]) {
			vvisited[i][(1 << cnt) - 1] = 1;
			solve(i, (1 << cnt) - 1);
		}
		ans = min(ans, dp[i][(1 << cnt) - 1]);
	}

	cout << ans;
}