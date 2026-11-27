#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> root;
int dx[] = { 0, -1, 0, 1 };
int dy[] = { 1, 0, -1, 0 };
int find(int x) {
	if (root[x] == x) return x;

	return root[x] = find(root[x]);
}

vector<pair<int, int>> A;
map<pair<int, int>, int> idx;
vector<tuple<int, int, int>> edge;

vector<string> grid;
bool inGrid(int x, int y) {
	return x >= 0 && x < n&& y >= 0 && y < n;
}

void bfs(int i) {
	queue<tuple<int, int, int>> q;
	q.push({ A[i].first , A[i].second, 0 });
	vector<vector<bool>> visit(n, vector<bool>(n));
	visit[A[i].first][A[i].second] = 1;
	while (!q.empty()) {

		int a, b, c;
		tie(a, b, c) = q.front();
		q.pop();

		for (int k = 0; k < 4; k++) {
			int na = a + dx[k];
			int nb = b + dy[k];

			if (inGrid(na, nb) && grid[na][nb] != '1' && !visit[na][nb]) {
				visit[na][nb] = 1;
				if (grid[na][nb] != '0') {
					int tt = idx[{na, nb}];
					edge.push_back({ c + 1, i, tt });
				}

				q.push({ na, nb, c + 1 });
			}
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

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (grid[i][j] == 'S' || grid[i][j] == 'K') {
				A.push_back({ i, j });
				idx[{i, j}] = cnt;
				cnt++;
			}
		}
	}

	for (int i = 0; i < cnt; i++) {
		bfs(i);
	}

	sort(edge.begin(), edge.end());

	root = vector<int>(cnt);
	for (int i = 1; i < cnt; i++) root[i] = i;

	int ans = 0;
	int conn = 0;
	for (auto i : edge) {

		int a, b, c;
		tie(a, b, c) = i;

		find(b), find(c);
		if (root[b] != root[c]) {
			ans += a;
			conn++;
			root[root[b]] = root[c];
		}

		if (conn == cnt - 1) break;
	}

	if (conn == cnt - 1) cout << ans;
	else cout << -1;
}