#include <bits/stdc++.h>
using namespace std;

int n, a, b, c, x, y;
vector<string> grid;
vector<vector<int>> dp;
map<pair<int, int>, bool> check;
priority_queue<tuple<int, int, int>> pq;  // wall-break count, r, c

int step[4][2] = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };

bool outofgrid(int r, int c) {
	return (r < 0 || r >= n) || (c < 0 || c >= n);
}

void bfs() {
	while (!pq.empty()) {
		tie(a, b, c) = pq.top();
		pq.pop();
		if (check[{b, c}] == 1) continue;
		check[{b, c}] = 1;
		for (int i = 0; i < 4; i++) {
			x = b + step[i][0];
			y = c + step[i][1];
			if (!outofgrid(x, y) && check[{x, y}] != 1) {
				if (grid[x][y] == '0') pq.push({ a - 1, x, y });
				else pq.push({ a, x, y });
			}
		}
		dp[b][c] = a * -1;
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n;
	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		grid.push_back(s);
	}

	dp = vector<vector<int>> (n, vector<int>(n));
	pq.push({ 0, 0, 0 });
	bfs();

	cout << dp[n - 1][n - 1];
}