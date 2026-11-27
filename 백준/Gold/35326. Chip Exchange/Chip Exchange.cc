#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

void solve() {
	ll a, b, c, d, e;
	cin >> a >> b >> c >> d >> e;

	ll v = b / d;
	a += c * v;
	b -= d * v;

	if (a >= e) {
		cout << 0 << '\n';
		return;
	}
	// cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << '\n';
	ll L = 1, R = 1e18;
	while (L <= R) {
		ll md = (L + R) >> 1;

		__int128 cur = md;

		__int128 ta = a, tb = b;
		cur -= d - 1 - tb % d;
		tb += d - 1 - tb % d;
		if (cur <= 0) {
			L = md + 1;
			continue;
		}

		// cout << "TESt : " << md << ' ' << cur << ' ' << ta << ' ' << tb << '\n';

		__int128 tta = ta, ttb = tb + cur;

		__int128 val1 = tta + cur / d * c + (cur % d);
		__int128 val2 = ta + cur;
		__int128 val3 = tta + ttb / d * c;
		if (min({val1, val2, val3}) >= e) {
			R = md - 1;
		} else {
			L = md + 1;
		}
	}
	cout << L << '\n';
}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 1;
	cin >> t;
	while (t--) { solve(); }
	return 0;
}