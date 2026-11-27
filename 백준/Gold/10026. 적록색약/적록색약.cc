#include <bits/stdc++.h>
using namespace std;

int n, a, b, x, y;
vector<string> grid;
queue<pair<int, int>> q;

bool check[100][100];

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

bool outofgrid(int r, int c) {
	return (r < 0 || r >= n) || (c < 0 || c >= n);
}

void bfs() {
	while (!q.empty()) {
		tie(a, b) = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			x = a + dx[i];
			y = b + dy[i];
			if (!outofgrid(x, y) && !check[x][y] && grid[x][y] == grid[a][b]) {
				check[x][y] = 1;
				q.push({ x,y });
			}
		}
	}
}

int main() {ios::sync_with_stdio(false);
cin.tie(nullptr);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		grid.push_back(s);
	}

	int cnt1 = 0;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++) {
			if (!check[i][j]) {
				check[i][j]=1;
				q.push({ i, j });
				bfs();
				cnt1++;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (grid[i][j] == 'G') grid[i][j] = 'R';
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			check[i][j] = 0;
		}
	}

	int cnt2 = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!check[i][j]) {
				check[i][j]=1;
				q.push({ i, j });
				bfs();
				cnt2++;
			}
		}
	}

	cout << cnt1 << ' ' << cnt2;
}
