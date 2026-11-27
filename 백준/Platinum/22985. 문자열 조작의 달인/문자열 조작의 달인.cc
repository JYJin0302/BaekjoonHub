#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 1e9 + 7;

ll dp[2][301][9000];

void solve() {
	ll n, m;
	cin >> n >> m;

	string s;
	cin >> s;

	m = min(m, n * 25);
	dp[0][0][0] = 1;

	for (int i = 0; i < n; i++) {
		int val = s[i] - 'a';
		for (int j = 0; j <= 25 - val; j++) {
			for (int f = 0; f + j <= m; f++) {
				if (j + val == 25) {
					(dp[1][i + 1][f + j] += dp[0][i][f] + dp[1][i][f]) %= mod;
				} else {
					(dp[0][i + 1][f + j] += dp[0][i][f]) %= mod;
					(dp[1][i + 1][f + j] += dp[1][i][f]) %= mod;
				}
			}
		}
	}

	ll ans = dp[0][n][m];
	for (int j = 0; j <= m; j++) ans += dp[1][n][j];
	cout << ans % mod << '\n';
}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 1;
	// cin >> t;
	while (t--) { solve(); }
	return 0;
}