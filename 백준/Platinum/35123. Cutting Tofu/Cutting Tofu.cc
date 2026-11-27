#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

bool chk(ll a, ll b, ll c, ll d) {
	if (a >= d || b >= d || c >= d) return 1;
	d = (d + a - 1) / a;
	if (b >= d || c >= d) return 1;
	d = (d + b - 1) / b;
	return c >= d;
}

void solve() {
	ll a, b, c, d;
	cin >> a >> b >> c >> d;

	ll ansP = 0;
	ll ansQ = 1;

	// a
	ll L = 1, R = d;
	while (L <= R) {
		ll md = (L + R) >> 1;

		// use length a / md
		ll ta = md;
		ll tb = b * md / a;
		ll tc = c * md / a;

		if (tb == 0 || tc == 0) {
			L = md + 1;
			continue;
		}

		if (chk(ta, tb, tc, d)) {
			// update
			if (ansP * md < ansQ * a) {
				ansP = a;
				ansQ = md;
			}
			R = md - 1;
		} else L = md + 1;
	}

	// b
	L = 1, R = d;
	while (L <= R) {
		ll md = (L + R) >> 1;

		// use length b / md
		ll ta = a * md / b;
		ll tb = md;
		ll tc = c * md / b;

		if (ta == 0 || tc == 0) {
			L = md + 1;
			continue;
		}

		if (chk(ta, tb, tc, d)) {
			// update
			if (ansP * md < ansQ * b) {
				ansP = b;
				ansQ = md;
			}
			R = md - 1;
		} else L = md + 1;
	}

	// c
	L = 1, R = d;
	while (L <= R) {
		ll md = (L + R) >> 1;

		// use length c / md
		ll ta = a * md / c;
		ll tb = b * md / c;
		ll tc = md;

		if (ta == 0 || tb == 0) {
			L = md + 1;
			continue;
		}

		if (chk(ta, tb, tc, d)) {
			// update
			if (ansP * md < ansQ * c) {
				ansP = c;
				ansQ = md;
			}
			R = md - 1;
		} else L = md + 1;
	}

	ll g = gcd(ansP, ansQ);
	ansP /= g, ansQ /= g;

	cout << ansP << ' ' << ansQ << '\n';
}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 1;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		// cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}