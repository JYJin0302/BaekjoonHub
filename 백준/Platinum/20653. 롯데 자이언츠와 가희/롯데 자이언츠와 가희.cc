#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll mod = 1e9 + 7;

ll fastPow(ll b, ll e) {

	ll res = 1, temp = b;

	while (e) {
		if (e % 2 == 1) {
			res *= temp;
		}
		res %= mod;
		temp *= temp;
		temp %= mod;
		e /= 2;
	}
	return res;
}


int main() {

	int t;
	cin >> t;

	while (t--) {

		ll n, G, L;
		cin >> n >> G >> L;

		if (L % G != 0) {
			cout << "0\n";
			continue;
		}

		ll a = L / G;

		vector<ll> p;
		
		for (int i = 2; i * i <= a; i++) {
			
			if (a % i == 0) {
				ll cnt = 0;
				while (a % i == 0) {
					cnt++;
					a /= i;
				}
				p.push_back(cnt);
			}
		}
		if (a != 1) p.push_back(1);

		ll ans = 1;

		for (auto i : p) {
            ll tans = fastPow(i+1, n);
            tans += 2*(mod - fastPow(i, n));
            tans %= mod;
            tans += fastPow(i-1, n);
            tans %= mod;
            
			ans *= tans;
			ans %= mod;
		}

		cout << ans << '\n';
	}
}