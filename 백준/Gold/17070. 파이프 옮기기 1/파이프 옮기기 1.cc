#include <bits/stdc++.h>
using namespace std;

int grid[16][16];  
int dp[16][16][3];  // 0: 가로, 1: 세로, 2: 대각선

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> grid[i][j];
		}
	}

	dp[0][1][0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (j == 0 && i <= 1 || grid[i][j] == 1) continue;

			if (i > 0 && j > 0) {
				if (grid[i - 1][j] != 1 && grid[i][j - 1] != 1) {
					dp[i][j][2] += dp[i - 1][j - 1][0] + dp[i - 1][j - 1][1] + dp[i - 1][j - 1][2];
				}
			}
			if (j > 0) dp[i][j][0] += dp[i][j - 1][0] + dp[i][j - 1][2];
			if (i > 0) dp[i][j][1] += dp[i - 1][j][1] + dp[i - 1][j][2];
		}
	}

	cout << dp[n - 1][n - 1][0] + dp[n - 1][n - 1][1] + dp[n - 1][n- 1][2];
}