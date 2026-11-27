#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define INF 1000000000

int main() {

	int n, m;
	cin >> n >> m;

	vector<vector<ll>> dp(n, vector<ll>(m + 1, INF));  // dp[a][b] : a번째 이름을 썼을 때 b칸 채우는 최소비용
	
	for (int i = 0; i < n; i++) {
		ll x;
		cin >> x;

		if (i == 0) dp[i][x] = 0;
		else {
			ll minn = INF;
			for (int j = 0; j <= m; j++) minn = min(minn, dp[i - 1][j] + (m - j) * (m - j));

			dp[i][x] = minn;
			for (int j = x + 1; j <= m; j++) dp[i][j] = dp[i-1][j - x - 1];
		}
	}

	ll ans = INF;
	for (int j = 0; j <= m; j++) {
		ans = min(ans, dp[n - 1][j]);
	}


	cout << ans;
}