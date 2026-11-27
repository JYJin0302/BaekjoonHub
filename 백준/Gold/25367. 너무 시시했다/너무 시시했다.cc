#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {

	ll a, b;
	cin >> a >> b;

	ll ia, ib;
	ia = a, ib = b;

	// x ^ (a-x) == b

	if (a < b) {
		cout << "0\n";
		return;
	}

	ll ans1 = 0, ans2 = 0;
	int px = -1;
	// px 자리에 0 0 배정 -> 필요시 1 1 로 변경 가능

	bool valid = 1;
	for (int i = 0; i < 63; i++) {

		ll tx = (1ll << i);

		bool ai = (tx & a) > 0;
		bool bi = (tx & b) > 0;

		if (!ai && !bi) {
			px = i;

		}
		else if (!ai) {
			if (px == -1) {
				valid = 0;
				break;
			}
			ans1 += (1ll << px);
			ans2 += (1ll << px);
			ans1 += (1ll << i);
			a -= (1ll << (i + 1));
			px = -1;
		}
		else if (!bi) {
			if (px == -1) {
				valid = 0;
				break;
			}

			ans1 += (1ll << px);
			ans2 += (1ll << px);
			
			px = i;
		}
		else {
			ans1 += (1ll << i);
			px = -1;
		}
	}

	if (!valid) cout << "0\n";
	else {
		ll res = 1;
		for (int i = 0; i < 63; i++) {

			ll tx = (1ll << i);

			bool ai = (tx & ans1) > 0;
			bool bi = (tx & ans2) > 0;

			if (ai != bi) res *= 2;
		}
		cout << res << '\n';

	}

}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}

}