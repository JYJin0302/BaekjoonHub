#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, k;
vector<ll> A = { 0 };

ll C[5001][5001];

vector<ll> dp, tmp;

void solve(int l, int r, int sl, int sr) {
	if (l > r) return;

	int m = (l + r) >> 1;

	ll ansV = -1, ansi = sl;

	for (int i = sl; i <= min(sr, m); i++) {
		ll tans = dp[i - 1] + C[i][m];
		if (tans > ansV) {
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
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		A.push_back(x);
	}

	for (int i = 0; i <= n; i++) {
		C[i][i] = A[i];
		for (int j = i; j <= n; j++) {
			C[i][j] = C[i][j-1] | A[j];
		}
	}

	dp = vector<ll>(n + 1);
	tmp = vector<ll>(n + 1);

	int tv = 0;
	for (int i = 1; i <= n; i++) {
		dp[i] = C[0][i];
	}

	for (int i = 2; i <= k; i++) {
		solve(1, n, 1, n);
		swap(dp, tmp);
	}

	cout << dp[n];
}