#include <bits/stdc++.h>
using namespace std;

int n, m;
int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };

bool inGrid(int x, int y) {
	return x >= 0 && x < n&& y >=0 && y < m;
}

int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		
		cin >> n >> m;
		
		vector<string> grid;
		vector<vector<pair<int, int>>> door(26);  // 도달가능한 곳에서 열리지 않는 문

		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;
			grid.push_back(s);
		}

		string k, key(26, '0');
		cin >> k;
		if (k != "0") {
			for (char c : k) key[c - 'a'] = '1';
		}

		vector<vector<bool>> check(n, vector<bool>(m));
		queue<pair<int, int>> q;

	    // 가장자리
		for (int i = 0; i < m; i++) {
			if (grid[0][i] != '*') {
				check[0][i] = 1;
				q.push({ 0, i });
			}
			if (grid[n - 1][i] != '*') {
				check[n - 1][i] = 1;
				q.push({ n - 1, i });
			}
		}

		for (int i = 1; i < n-1; i++) {
			if (grid[i][0] != '*') {
				check[i][0] = 1;
				q.push({ i, 0 });
			}
			if (grid[i][m-1] != '*'){
				check[i][m - 1] = 1;
				q.push({ i, m-1 });
			}
		}

		// bfs
		int ans = 0;
		while (!q.empty()) {
			int a, b;
			tie(a, b) = q.front();
			
			q.pop();
			if (grid[a][b] >= 'A' && grid[a][b] <= 'Z') {
				if (key[grid[a][b] - 'A'] == '0') {
					door[grid[a][b] - 'A'].push_back({ a, b });
					continue;
				}
			}
			else if (grid[a][b] >= 'a' && grid[a][b] <= 'z') {
				key[grid[a][b] - 'a'] = '1';
				for (auto k : door[grid[a][b] - 'a']) {
					q.push(k);
				}
			}
			else if (grid[a][b] == '$') ans++;

			for (int i = 0; i < 4; i++) {
				int x = a + dx[i];
				int y = b + dy[i];
				if (inGrid(x, y) && grid[x][y] != '*' && check[x][y] == 0) {
					check[x][y] = 1;
					q.push({ x, y });
				}
			}
		}
		
		cout << ans << '\n';
	}
}