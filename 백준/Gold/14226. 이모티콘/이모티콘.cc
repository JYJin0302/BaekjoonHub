#include <bits/stdc++.h>
using namespace std;

int dp[2001][1001];  // 현재 길이, 클립보드 길이

int main() {

	int n;
	cin >> n;

	memset(dp, -1, sizeof(dp));

	dp[1][0] = 0;
	queue<pair<int, int>> q;
	q.push({ 1, 0 });
	while (!q.empty()) {

		int a, b;
		tie(a, b) = q.front();
		q.pop();
		if (a == n) {
			cout << dp[a][b];
			break;
		}

		if (a > 0) {
			if (dp[a - 1][b] == -1) {
				dp[a - 1][b] = dp[a][b] + 1;
				q.push({ a - 1, b });
			}
		}

		if (dp[a][a] == -1) {
			dp[a][a] = dp[a][b] + 1;
			q.push({ a, a });
		}

		if (a < n && dp[a+b][b] == -1) {
			dp[a + b][b] = dp[a][b] + 1;
			q.push({ a + b,b });
		}

	}
}