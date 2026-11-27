#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int A[21][21];
int cnt1[21][21], cnt2[21][21];
int dp[21][21][21][21][2];

int solve(int xl, int xr, int yl, int yr, int t) {
	// t : 0 가로 컷 1 세로 컷

	if (dp[xl][xr][yl][yr][t] != -1) return dp[xl][xr][yl][yr][t];

	int c1 = cnt1[xr][yr] - cnt1[xl - 1][yr] - cnt1[xr][yl - 1] + cnt1[xl - 1][yl - 1];
	int c2 = cnt2[xr][yr] - cnt2[xl - 1][yr] - cnt2[xr][yl - 1] + cnt2[xl - 1][yl - 1];

	if (c1 == 0 && c2 == 1) {
		return dp[xl][xr][yl][yr][t] = 1;
	}
	if (c2 == 0) return dp[xl][xr][yl][yr][t] == 0;

	int res = 0;
	if (t == 0) {
		for (int i = xl + 1; i <= xr - 1; i++) {
			int tc1 = cnt1[i][yr] - cnt1[i][yl - 1] - cnt1[i - 1][yr] + cnt1[i - 1][yl - 1];
			int tc2 = cnt2[i][yr] - cnt2[i][yl - 1] - cnt2[i - 1][yr] + cnt2[i - 1][yl - 1];
			if (tc2 == 0 && tc1 != 0) {
				res += solve(xl, i - 1, yl, yr, 1 - t) * solve(i + 1, xr, yl, yr, 1 - t);
			}
		}
	}
	else {
		for (int i = yl + 1; i <= yr - 1; i++) {
			int tc1 = cnt1[xr][i] - cnt1[xl - 1][i] - cnt1[xr][i - 1] + cnt1[xl - 1][i - 1];
			int tc2 = cnt2[xr][i] - cnt2[xl - 1][i] - cnt2[xr][i - 1] + cnt2[xl - 1][i - 1];
			if (tc2 == 0 && tc1 != 0) {
				res += solve(xl, xr, yl, i-1, 1 - t) * solve(xl, xr, i + 1, yr, 1 - t);
			}
		}
	}

	return dp[xl][xr][yl][yr][t] = res;
}


int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	memset(dp, -1, sizeof(dp));

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> A[i][j];

			if (A[i][j] == 1) cnt1[i][j]++;
			else if (A[i][j] == 2) cnt2[i][j]++;

			if (i > 0) {
				cnt1[i][j] += cnt1[i - 1][j];
				cnt2[i][j] += cnt2[i - 1][j];
			}
			if (j > 0) {
				cnt1[i][j] += cnt1[i][j - 1];
				cnt2[i][j] += cnt2[i][j - 1];
			}
			if (i && j) {
				cnt1[i][j] -= cnt1[i - 1][j - 1];
				cnt2[i][j] -= cnt2[i - 1][j - 1];
			}
		}
	}

	int ans = solve(1, n, 1, n, 0) + solve(1, n, 1, n, 1);
	if (ans == 0) ans = -1;
	cout << ans;

}