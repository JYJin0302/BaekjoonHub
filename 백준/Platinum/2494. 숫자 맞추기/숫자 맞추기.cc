#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;

	string s1, s2;
	cin >> s1 >> s2;

	vector<vector<int>> dp(n + 1, vector<int>(10, INF));

	dp[0][0] = 0;

	for (int i = 1; i <= n; i++) {

		int x = s1[i-1] - '0';
		int tx = s2[i-1] - '0';


		for (int j = 0; j < 10; j++) {
			int xx = (x + j) % 10;
			// 오른쪽으로 돌림
			dp[i][j] = min(dp[i][j], dp[i - 1][j] + (xx - tx + 10) % 10);
			
			int ttx = (tx - xx + 10) % 10;  // 왼쪽 돌리는 횟수
			dp[i][(j + ttx) % 10] = min(dp[i][(j + ttx) % 10], dp[i - 1][j] + ttx);
		}
	}

	int ans = INF, ansi = -1;
	for (int i = 0; i < 10; i++) {
		if (dp[n][i] < ans) {
			ans = dp[n][i];
			ansi = i;
		}
	}

	cout << ans << '\n';
	for (int i = n; i >= 1; i-- ) {
		int x = s1[i - 1] - '0';
		int tx = s2[i - 1] - '0';

		for (int j = 0; j < 10; j++) {
			int xx = (x + j) % 10;
			// 오른쪽으로 돌림
			if (ansi == j && dp[i][j] == dp[i - 1][j] + (xx - tx + 10) % 10) {
				cout << i << ' ' << -(xx - tx + 10) % 10 << '\n';
				break;
			}

			int ttx = (tx - xx + 10) % 10;  // 왼쪽 돌리는 횟수
			if ((j + ttx) % 10 == ansi && dp[i][(j + ttx) % 10] == dp[i - 1][j] + ttx) {
				cout << i << ' ' << ttx << '\n';
				ansi = j;
				break;
			}
		}
	}
}