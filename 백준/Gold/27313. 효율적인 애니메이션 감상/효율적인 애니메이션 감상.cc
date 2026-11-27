#include <bits/stdc++.h>
using namespace std;
using ll = long long;


void solve() {

	ll n, m, k;
	cin >> n >> m >> k;

	k = min(k, n);
	vector<ll> A(n);
	for (auto& i : A) cin >> i;

	sort(A.begin(), A.end());

	vector<ll> dp(n);
	for (int i = 0; i < k; i++) dp[i] = A[i];
	for (int i = k; i < n; i++) {
		dp[i] = A[i] + dp[i - k];
	}


	int ans = -1;
	for (int i = 0; i < n; i++) {
		if (dp[i] <= m) ans = i;
	}

	cout << ans + 1;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}

}