#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

const int mod = 998244353;
ll F[2001010];
ll fastPow(ll b, ll ex) {
	ll res = 1;
	while (ex) {
		if (ex & 1) res = res * b % mod;
		b = b * b % mod;
		ex >>= 1;
	}
	return res;
}

ll nCr(ll n, ll r) { return F[n] * fastPow(F[n - r], mod - 2) % mod * fastPow(F[r], mod - 2) % mod; }

ll cal(ll n, ll k, ll m) {
	ll ret = 0;
	for (int i = 0; i <= n; i++) {
		if ((m + 1) * i > k) break;
		ll tn = n;
		ll tr = k - (m + 1) * i;

		ll res = nCr(tn + tr - 1, tr) * nCr(n, i) % mod;
		if (i & 1) ret = (ret + mod - res) % mod;
		else ret = (ret + res) % mod;
	}
	return ret;
}

void solve() {
	ll n, k, m;
	cin >> n >> k >> m;
	F[0] = 1;
	for (int i = 1; i <= n + k + 10; i++) { F[i] = F[i - 1] * i % mod; }

	ll ans1 = cal(n, k, m);
	ll ans2 = cal(n, k - 1, m - 1);
	cout << (ans1 + mod - ans2) % mod << '\n';
}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 1;
	// cin >> t;
	for (int i = 1; i <= t; i++) {
		// cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}