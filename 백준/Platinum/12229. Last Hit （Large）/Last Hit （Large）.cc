#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int hp[101], gold[101];
int dp[101][1001];

const int INF = 1e9;

void solve() {

	int p, q, n;
	cin >> p >> q >> n;

	for (int i = 0; i < n; i++) {
		cin >> hp[i] >> gold[i];
	}

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= 1000; j++) {
			dp[i][j] = -INF;

			// i : idx, j : 여유 턴 수
		}
	}
	dp[0][1] = 0;


	for (int i = 1; i <= n; i++) {

		int v = (hp[i-1] + q-1) / q, r = hp[i-1] % q;
		
		if (r == 0) r = q;
		int nd = (r + p - 1) / p - v+1;
		int en = v;

		for (int j = 0; j <= 1000; j++) {

			if (j+nd <= 1000 && j+nd >= 0 && dp[i-1][j+nd] != -INF) dp[i][j] = max(dp[i][j], dp[i-1][j+nd] + gold[i-1]);
			if (j - en >= 0 && dp[i-1][j-en] != -INF) dp[i][j] = max(dp[i][j], dp[i - 1][j - en]);

		}
	}


	int ans = -1;
	for (int i = 0; i <= 1000; i++) {
		ans = max(ans, dp[n][i]);
	}
	cout << ans << '\n';

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
	int t;
	cin >> t;
	for(int i = 1; i <= t; i++){
		cout << "Case #" << i << ": ";
		solve();
	}
}