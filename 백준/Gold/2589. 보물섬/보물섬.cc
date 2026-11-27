#include <bits/stdc++.h>
using namespace std;

int maxcnt, n, m,a ,b, cnt, tx, ty;

vector<string> grid;
vector<vector<bool>> visited;
vector<pair<int, int>> tempvisit;
queue<pair<int, int>> q;
queue<pair<int, int>> tq;
int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1, 0 };

bool valid_position(int x, int y) {
	return (x >= 0 && x < n) && (y >= 0 && y < m) && grid[x][y] != 'W' && !visited[x][y];
}

void bfs() {
	while (!q.empty()) {
		tie(a, b) = q.front();
		tempvisit.push_back({ a, b });
		q.pop();
		for (int i = 0; i < 4; i++) {
			tx = a + dx[i];
			ty = b + dy[i];
			if (valid_position(tx, ty)) {
				visited[tx][ty] = 1;
				tq.push({ tx,ty });
			}
		}
	}
	swap(tq, q);
		
	if (q.empty()) return;
	cnt++;
	bfs();
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
	visited = vector<vector<bool>>(n, vector<bool>(m));

	int ans = -1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (grid[i][j] == 'L') {
				visited[i][j] = 1;
				cnt = 0;
				q.push({ i, j });
				bfs();
				for (auto i : tempvisit) {
					tie(tx, ty) = i;
					visited[tx][ty] = 0;
				}
				tempvisit.clear();
                visited[i][j] = 0;

				ans = max(ans, cnt);
			}
		}
	}
	cout << ans;
}