#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b) {
	if (a > b) swap(a, b);
	if (a == 0) return b;
	return gcd(b % a, a);
}

ll lcm(ll a, ll b) {
	return a * b / gcd(a, b);
}

ll fastPow(ll b, ll ex, ll m) {
	ll res = 1;
	while (ex) {
		if (ex & 1) res = res * b % m;
		b = b * b % m;
		ex >>= 1;
	}
	return res;
}



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n, a, b, c, d;
	cin >> n >> a >> b >> c >> d;

	vector<int> A(n + 1);
	for (int i = 1; i <= n; i++) cin >> A[i];

	vector<bool> vs(n+1);
	ll ans = 1;
	for (int i = c + 1; i <= n-d; i++) {
		if (vs[i]) continue;

		int ix = i;
		int len = 0;
		while (!vs[ix]) {
			vs[ix] = 1;
			len++;
			ix = A[ix];
		}
		
		ll ta = len / gcd(ans, len);
		if (b / ta < ans) ans = b + 1;
		else ans = ans * ta;
	}

	b--, a--;

	ll res = b / ans + 1;
	if (a > 0) res -= (a - 1) / ans + 1;
	cout << res;
}