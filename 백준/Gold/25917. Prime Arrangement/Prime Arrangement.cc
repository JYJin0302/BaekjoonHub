#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mod = 998244353;

ll fastPow(ll b, ll ex) {
	ll res = 1;
	while (ex) {
		if (ex % 2) res = res * b % mod;
		b = b * b % mod;
		ex /= 2;
	}
	return res;
}

int main() {

	int r, c;
	cin >> r >> c;

	int n = r * c;
	for (int i = 0; i < n + r; i++) {
		int x;
		cin >> x;
	}

	vector<ll> f(n + 1);
	f[0] = 1;
	for (int i = 1; i <= n; i++) f[i] = f[i - 1] * i % mod;

	ll ans = f[n] * fastPow(f[r], mod - 2) % mod;
	cout << ans;

}