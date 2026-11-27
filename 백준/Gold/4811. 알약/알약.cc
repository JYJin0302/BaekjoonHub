#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);
	int n;
	cin >> n;
	while (n != 0) {

		vector<vector<ll>> dp(n+1, vector<ll>(n + 1));  // 한 조각 꺼낸 횟수, 반조각 꺼낸 횟수
		dp[1][0] = 1;

		for (int i = 1; i <= n; i++) {
			for (int j = 0; j <= i; j++) {
				if (j == 0) dp[i][j] = 1;
				else dp[i][j] += dp[i][j - 1] + dp[i - 1][j];
			}
		}

		cout << dp[n][n] << '\n';

		cin >> n;
	}
}