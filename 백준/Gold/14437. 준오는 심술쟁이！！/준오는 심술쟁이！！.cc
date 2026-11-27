#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define INF 1000000000

int main() {

	ll n, m, mod = 1e9 + 7;
	cin >> n;

	string s;
	cin >> s;

	m = s.size();
	swap(n, m);

	vector<vector<ll>> dp(n + 1, vector<ll>(m + 1));
	dp[0][0] = 1;

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			
			dp[i][j] = dp[i - 1][j];
			if (j > 0) dp[i][j] += dp[i][j - 1];
			if (j > 25) dp[i][j] -= dp[i-1][j - 26];

			dp[i][j] = (dp[i][j] + mod) % mod;
		}
	}

	cout << dp[n][m];

}