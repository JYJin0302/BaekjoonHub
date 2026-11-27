#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };
bool path[1000][1000][11];

bool inGrid(int x, int y) {
	return x >= 0 && x < n&& y >=0 && y < m;
}

int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);
	cin >> n >> m >> k;
	
	vector<string> grid(n);
	for (auto& i : grid) cin >> i;

	queue<tuple<int, int, int, int>> q;  // x, y, 벽 부순 횟수, 길이

	q.push({ 0, 0, 0, 1 });
	path[0][0][0] = 1;
	while (!q.empty()) {
		int a, b, c, d;
		tie(a, b, c, d) = q.front();
		q.pop();
		if (a == n - 1 && b == m - 1) {
			cout << d;
			return 0;
		}
		
		for (int i = 0; i < 4; i++) {
			int na = a + dx[i];
			int nb = b + dy[i];
			if (inGrid(na, nb)) {
				if (grid[na][nb] == '1' && c < k && !path[na][nb][c+1]) {
					path[na][nb][c + 1] = 1;
					q.push({ na, nb, c + 1, d + 1 });
				}
				else if (grid[na][nb] == '0' && !path[na][nb][c]) {
					path[na][nb][c] = 1;
					q.push({ na, nb, c, d + 1 });
				}
			}
		}
	}

	cout << -1;
}