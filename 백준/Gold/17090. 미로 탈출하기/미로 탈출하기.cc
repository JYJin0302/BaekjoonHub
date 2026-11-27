#include <bits/stdc++.h>
using namespace std;

int n, m, ans;
vector<string> grid;
vector<vector<int>> dp;

bool outofgrid(int r, int c) {
	return (r < 0 || r >= n) || (c < 0 || c >= m);
}

int dfs(int r, int c) {
	if (outofgrid(r, c)) return 1;
	if (dp[r][c] != 0) return dp[r][c];

	char i = grid[r][c];
	dp[r][c] = -1;
	switch(i) {
	case 'U':
		return dp[r][c] = dfs(r - 1, c);
	case 'D':
		return dp[r][c] = dfs(r + 1, c);
	case 'L':
		return dp[r][c] = dfs(r, c - 1);
	case 'R':
		return dp[r][c] = dfs(r, c + 1);
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		grid.push_back(s);
	}
	dp = vector<vector<int>>(n, vector<int>(m));

	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
		dfs(i, j);
	}

	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
		if (dp[i][j] == 1) ans++;
	}
	cout << ans;
}