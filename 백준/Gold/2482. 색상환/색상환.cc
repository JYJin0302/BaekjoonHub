#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	int n, k;
	ll mod = 1000000003;
	cin >> n >> k;
	vector<vector<ll>> dp(n + 1, vector<ll>(k + 1));

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= min(i, k); j++) {
			if (j == 0) dp[i][j] = 1;
			else if (j == 1) dp[i][j] = i;
			else dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % mod;
		}
	}
	if (k > n / 2) cout << 0;
	else if (k == 1) cout << dp[n - k + 1][k];
	else {
		ll ans = dp[n - k + 1][k] - dp[n - k - 1][k - 2];
		if (ans < 0) ans += mod;
		cout << ans;
	}
}