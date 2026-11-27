#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

void solve() {
	ll T, c, t;
	cin >> T >> c >> t;
	if (T == 1) {
		if (t < 2 * c) {
			cout << c << '\n';
			return;
		}
		if (c == 0 && t <= 1) {
			cout << 0 << '\n';
			return;
		}

		ll curPos = c;
		ll curT = 2 * c - 1;
		if (c == 0) curT = 1;

		while (curT < t) {
			if (curPos == 0) {
				curT++;
				curPos = curT >> 1;
			} else {
				ll rem = t - curT;
				ll mn = min(rem, curPos);
				curPos -= mn;
				curT += mn;
			}
		}
		cout << curPos << '\n';
	} else {
		ll curPos = c;
		ll curT = t;
		while (curT && curT / 2 >= curPos) {
			// cout << "state1 : " << curPos << ' ' << curT << '\n';
			ll val = (curT - 2 * curPos) / 3;
			val = max(0ll, val - 1);

			// simul val
			curPos += val;
			curT -= val;
			// cout << "state2 : "<< curPos << ' ' << curT << '\n';
			if (curT / 2 == curPos) {
				curT--;
				curPos = 0;
			} else {
				curT--;
				curPos++;
			}
		}

		cout << curPos << '\n';
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 1;
	cin >> t;
	while (t--) { solve(); }
	return 0;
}