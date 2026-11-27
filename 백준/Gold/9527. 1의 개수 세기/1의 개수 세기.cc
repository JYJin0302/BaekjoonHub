#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve(ll x) {

	ll res = 0;

	vector<ll> temp(62);

	for (ll i = 60; i >= 0; i--) {
		bool is = (x & (1ll << i)) != 0;
		temp[i] = temp[i + 1] * 2 + is;
	}

	for (ll i = 60; i >= 0; i--) {
		bool is = (x & (1ll << i)) != 0;
		res += temp[i + 1] * (1ll << i) + is * (x % (1ll << i) + 1);
	}

	return res;
}

int main() {

	ll a, b;
	cin >> a >> b;

	cout << solve(b) - solve(a - 1);
}