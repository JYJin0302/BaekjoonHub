#include <bits/stdc++.h>
using namespace std;
using ll= long long;

// dp[i][j]: i개의 'a' 과 j개의 'z'로 만들어지는 모든 문자열의 경우의 수
ll dp[101][101];

int main() {
	ll n, m, k;
	cin >> n >> m >> k;

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			if (i == 0 || j == 0) dp[i][j] = 1;
			else dp[i][j] = min(1000000000ll, dp[i - 1][j] + dp[i][j - 1]);
		}
	}

	
	string ans = "";
	
	if (dp[n][m] < k) {
		cout << -1;
		return 0;
	}
	while (dp[n - 1][m] == 1000000000 && n) {
		ans += 'a';
		n--;
	}

	while (n && m) {
		if (k > dp[n - 1][m]) {
			k -= dp[n - 1][m];
			ans += 'z';
			m--;
		}
		else {
			ans += 'a';
			n--;
		}
	}
	string temp = "";
	if (m) temp = string(m, 'z');
	if (n) temp = string(n, 'a');
	cout << ans << temp;
}