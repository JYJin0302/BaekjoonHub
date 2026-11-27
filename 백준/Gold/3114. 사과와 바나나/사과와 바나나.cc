#include <bits/stdc++.h>
using namespace std;

pair<int, int> base[1500][1500];

// x, y
int apple[1500][1500];  // 수직방향 합
int banana[1500][1500];  // 수평방향 합

int dp[1500][1500];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			string s;
			cin >> s;
			base[i][j] = { s[0], stoi(s.substr(1, 2)) };
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (base[i][j].first == 'B') {
				if (i > 0) apple[i][j] = apple[i - 1][j];
				if (j == 0) banana[i][j] = base[i][j].second;
				else banana[i][j] = banana[i][j-1] + base[i][j].second;
			}
			else {
				if (i == 0) apple[i][j] = base[i][j].second;
				else apple[i][j] = apple[i - 1][j] + base[i][j].second; 
				if (j > 0) banana[i][j] = banana[i][j - 1];
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i > 0 && j > 0) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + apple[n - 1][j - 1] - apple[i - 1][j - 1] + banana[i - 1][m - 1] - banana[i - 1][j - 1]);
			if (i > 0) dp[i][j] = max(dp[i][j], dp[i - 1][j] + banana[i - 1][m - 1] - banana[i - 1][j]);
			if (j > 0) dp[i][j] = max(dp[i][j], dp[i][j - 1] + apple[n - 1][j - 1] - apple[i][j - 1]);
		}
	}
	cout << dp[n - 1][m - 1];
}