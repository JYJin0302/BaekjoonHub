#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<string> grid;
vector<vector<int>> path;
vector<vector<bool>> check;
bool infinite = 0;

int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };

bool inGrid(int x, int y) {
	return x >= 0 && x < n&& y >= 0 && y < m;
}

void dfs(int x = 0, int y = 0) {

	vector<int> temp(4);

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i] * (grid[x][y] - '0');
		int ny = y + dy[i] * (grid[x][y] - '0');

		if (inGrid(nx, ny) && grid[nx][ny] != 'H') {
            
			if (check[nx][ny] && path[nx][ny] == 0) {
				infinite = 1;
				return;
			}

			if (check[nx][ny]) {
				temp[i] = path[nx][ny];
			}
			else {
				check[nx][ny] = 1;
				dfs(nx, ny);
				temp[i] = path[nx][ny];
			}

			if (infinite) return;
		}
	}

	path[x][y] = *max_element(temp.begin(), temp.end()) + 1;
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

	check = vector<vector<bool>>(n, vector<bool>(m));
	path = vector<vector<int>>(n, vector<int>(m));
	check[0][0] = 1;
	dfs();

	if (infinite) cout << -1;
	else cout << path[0][0];
}