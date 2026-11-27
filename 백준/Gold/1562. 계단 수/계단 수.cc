#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll dp[101][1 << 10][10];  // 길이, 숫자들, 마지막 숫자

int main() {

	int n, mod = 1e9;
	cin >> n;

	for (int i = 1; i <= 9; i++) {
		dp[1][1 << i][i] = 1;
	}

	for (int i = 2; i <= n; i++) {

		for (int j = 1; j < (1 << 10); j++) {
			for (int k = 0; k < 10; k++) {

				if (j & (1 << k)) {

					if (k < 9) {
						dp[i][j][k] += dp[i - 1][j - (1 << k)][k + 1];
						dp[i][j][k] += dp[i - 1][j][k + 1];
					}
					if (k > 0) {
						dp[i][j][k] += dp[i - 1][j - (1 << k)][k - 1];
						dp[i][j][k] += dp[i - 1][j][k - 1];
					}

					dp[i][j][k] %= mod;
				}

			}
		}

	}

	ll ans = 0;
	for (int i = 0; i <= 9; i++) {
		ans += dp[n][(1 << 10) - 1][i];
		ans %= mod;
	}
	cout << ans;
}