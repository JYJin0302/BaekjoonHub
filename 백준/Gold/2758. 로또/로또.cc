#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll dp[2001][11];  // 최댓값, 개수

int main() {

	for (int i = 1; i <= 2000; i++) {
		dp[i][1] = 1;
	}
	for (int i = 1; i <= 2000; i++) {
		for (int j = 2; j <= 10; j++) {
			for (int k = 1; k <= i / 2; k++) {
				dp[i][j] += dp[k][j - 1];
			}
		}
	}
	int t, n, m;
	cin >> t;
	while (t--) {
		cin >> n >> m;

		ll ans = 0;
		for (int i = 1; i <= m; i++) {
			ans += dp[i][n];
		}
		cout << ans << '\n';
	}
}