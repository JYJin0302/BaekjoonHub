#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000

int dist(pair<int, int>a, pair<int, int>b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;

	pair<int, int> L = { 1, 1 }, R = { n ,n };
	vector<pair<int, int>> A(m+1);

	for (int i = 1; i <= m; i++) {
		int a, b;
		cin >> a >> b;
		A[i] = { a, b };
	}

	vector<vector<int>> dp(m + 1, vector<int>(m + 1, INF));
	dp[0][1] = dist(R, A[1]);
	dp[1][0] = dist(L, A[1]);

	for (int i = 2; i <= m; i++) {

		for (int j = 0; j < i - 1; j++) {
			if (j != 0) dp[i][i - 1] = min(dp[i][i - 1], dp[j][i - 1] + dist(A[j], A[i]));
			else dp[i][i - 1] = min(dp[i][i - 1], dp[j][i - 1] + dist(L, A[i]));

			dp[j][i] = min(dp[j][i], dp[j][i - 1] + dist(A[i - 1], A[i]));

			if (j != 0) dp[i-1][i] = min(dp[i-1][i], dp[i-1][j] + dist(A[j], A[i]));
			else dp[i-1][i] = min(dp[i-1][i], dp[i-1][j] + dist(R, A[i]));

			dp[i][j] = min(dp[i][j], dp[i-1][j] + dist(A[i - 1], A[i]));
		}
	}

	int ans = INF;
	pair<int, int> ansi;
	for (int i = 0; i < m; i++) {
		if (ans > dp[m][i]) {
			ansi = { m, i };
			ans = dp[m][i];
		}
		if (ans > dp[i][m]) {
			ansi = { i, m };
			ans = dp[i][m];
		}
	}

	cout << ans << '\n';

	vector<int> res;
	int search = m - 1;
	while (search >= 0) {

		int a, b;
		tie(a, b) = ansi;
		if (a > b) {
			res.push_back(1);
			if (b != search) {
				ansi = { search, b };
			}
			else {
				for (int k = 0; k < search; k++) {
					int d;
					if (k == 0) d = dist(L, A[search + 1]);
					else d = dist(A[k], A[search + 1]);

					if (dp[k][search] + d == dp[a][b]) {
						ansi = { k, search };
						break;
					}
				}
			}
		}
		else {
			res.push_back(2);
			if (a != search) {
				ansi = { a, search };
			}
			else {
				for (int k = 0; k < search; k++) {
					int d;
					if (k == 0) d = dist(R, A[search + 1]);
					else d = dist(A[k], A[search + 1]);

					if (dp[search][k] + d == dp[a][b]) {
						ansi = { search, k };
						break;
					}
				}
			}
		}

		search--;
	}

	reverse(res.begin(), res.end());

	for (int i : res) cout << i << '\n';
}