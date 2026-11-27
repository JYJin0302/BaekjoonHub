#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

const int mod = 998244353;

ll dp[3001 * 25];

void solve() {
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;

	m = min(m, 25 * n);
	dp[0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= m; j++) { dp[j] += dp[j - 1]; }
		for (int j = m; j >= 0; j--) {
			if (j >= 26) dp[j] -= dp[j - 26];
			dp[j] %= mod;
		}
	}

	ll ans = 0;
	for (int i = 0; i <= m; i++) ans += dp[i];
	ans %= mod;
	cout << ans << '\n';
}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 1;
	// cin >> t;
	for (int i = 1; i <= t; i++) { solve(); }
	return 0;
}