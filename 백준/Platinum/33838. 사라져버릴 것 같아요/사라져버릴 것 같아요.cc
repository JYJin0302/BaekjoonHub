#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

const int mod = 1e9 + 7;
ll f[202020];

ll fastPow(ll b, ll ex){
	ll res = 1;
	while(ex){
		if (ex & 1) res= res*b  % mod;
		b =b* b % mod;
		ex >>= 1;
	}
	return res;
}

ll nCr(ll n, ll r){
	return f[n] * fastPow(f[n-r], mod-2) % mod * fastPow(f[r], mod-2) % mod;
}
ll nHr(ll n, ll r){
	return nCr(n+r-1, r);
}
void solve() {
	
	int n, a, b, c;
	cin >> n >> a >> b >> c;

	if((b & 1) || a + b + c > n) {
		cout << 0 << '\n';
		return;
	}

	ll ans = f[c];

	ans = ans * f[b] % mod;
	ans = ans * fastPow(f[b/2], mod-2) % mod;
	// b/2 H c
	ans = ans * nHr(b/2, c) % mod;

	ll rem = n - a - b - c;
	a += b/2;
	rem -= a - 1;

	if (rem < 0){
		cout << 0 << '\n';
		return;
	}
	// a-1 H rem
	ans = ans * nHr(a+1, rem) % mod;
	ans = ans * f[a] % mod;

	cout << ans << '\n';

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	f[0] = 1;
	for(int i = 1; i <= 200000; i++) f[i] = f[i-1] * i % mod;

	int t = 1;
 	cin >> t;
	while (t--) { solve(); }
}