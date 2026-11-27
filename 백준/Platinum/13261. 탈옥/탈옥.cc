#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> dp, tmp;
ll A[8001], sA[8001];

void solve(int l, int r, int sl, int sr) {

	if (l > r) return;
	int m = (l + r) >> 1;

	ll ansVal = 1e17, ansi = -1;
	for (int i = sl; i <= min(sr, m); i++) {
		ll tans = dp[i - 1] + (sA[m] - sA[i - 1]) * (m - i+1);
		if (ansVal > tans) {
			ansVal = tans;
			ansi = i;
		}
	}

	tmp[m] = ansVal;
	solve(l, m-1, sl, ansi);
	solve(m + 1, r, ansi, sr);
}


int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) cin >> A[i];
	for (int i = 1; i <= n; i++) sA[i] = sA[i - 1] + A[i];

	dp = vector<ll>(n + 1);
	tmp = vector<ll>(n + 1);

	for (int i = 1; i <= n; i++) {
		dp[i] = sA[i] * i;
	}

	for (int i = 2; i <= m; i++) {
		solve(1, n, 1, n);
		swap(tmp, dp);
	}
	cout << dp[n];

}