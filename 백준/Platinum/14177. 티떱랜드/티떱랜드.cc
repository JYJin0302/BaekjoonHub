#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, k;
int A[4001][4001];
int As[4001][4001];
int C[4001][4001];

vector<int> dp, tmp;

void solve(int l, int r, int sl, int sr) {
	if (l > r) return;

	int m = (l + r) >> 1;

	int ansV = 1e9, ansi = -1;
	for (int i = sl; i <= min(m, sr); i++) {
		int tans = dp[i - 1] + C[i][m];
		if (ansV > tans) {
			ansV = tans;
			ansi = i;
		}
	}

	tmp[m] = ansV;
	solve(l, m - 1, sl, ansi);
	solve(m + 1, r, ansi, sr);
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> A[i][j];
			As[i][j] = As[i][j - 1] + A[i][j];
		}
	}

	for (int j = n; j >= 1; j--) {
		C[j][j] = 0;
		for (int i = j-1; i >= 1; i--) {
			C[i][j] = C[i + 1][j] + As[i][j] - As[i][i];
		}
		C[0][j] = C[1][j];
	}

	dp = vector<int>(n + 1);
	tmp = vector<int>(n + 1);
	for (int i = 1; i <= n; i++) dp[i] = C[0][i];

	for (int i = 2; i <= k; i++) {
		solve(1, n, 1, n);
		swap(dp, tmp);
	}
	cout << dp[n];

}