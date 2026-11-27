#include <bits/stdc++.h>
using namespace std;

int n, m, cnt = 1, a, b;
vector<string> grid;
int zero[1000][1000];
int zeros[1000][1000];
bool check[1000][1000];

queue<pair<int, int>> q;

int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };

bool valid(int x, int y) {
	return (x >= 0 && x < n&& y >= 0 && y < m) && grid[x][y] != '1';
}

void bfs() {
	vector<pair<int, int>> diff;
	while (!q.empty()) {
		tie(a, b) = q.front();
		diff.push_back({ a, b });
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ta, tb;
			ta = a + dx[i];
			tb = b + dy[i];
			if (valid(ta, tb) && !check[ta][tb]) {
				check[ta][tb] = 1;
				q.push({ ta, tb });
			}
		}
	}
	int size = diff.size();
	for (auto i : diff) {
		tie(a, b) = i;
		zero[a][b] = cnt;
		zeros[a][b] = size;
	}
	diff.clear();
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

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (grid[i][j] == '0' && zero[i][j] == 0) {
				check[i][j] = 1;
				q.push({ i, j });
				bfs();
				cnt++;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (grid[i][j] == '0') continue;
			int temp = 1;
			vector<bool> check1(cnt);
			for (int k = 0; k < 4; k++) {
				int ti = i + dx[k];
				int tj = j + dy[k];
				if (valid(ti, tj) && !check1[zero[ti][tj]]) {
					check1[zero[ti][tj]] = 1;
					temp += zeros[ti][tj];
				}
			}
			grid[i][j] = (temp % 10) + '0';
		}
	}
	for (int i = 0; i < n; i++) {
		cout << grid[i] << '\n';
	}
}