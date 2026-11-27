#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

void solve() {
	__int128 T, K1, K2, P1, P2;
	
	// input
	ll x;
	cin >> x;
	T = x;
	cin >> x;
	K1= x;
	cin >> x;
	P1 = x;
	cin >> x;
	K2 = x;
	cin >> x;
	P2 = x;

	__int128 ans = T * 10;
	ll lim = 1e6;

	if (K1 >= lim) {
		for (ll j = 0;; j += K1) {
			__int128 nd = T - j;
			if (nd <= 0) {
				ans = min(ans, j / K1 * P1);
				break;
			}
			__int128 rem = nd % K2;
			__int128 val = min({(nd + K2 - 1) / K2 * P2, nd / K2 * P2 + rem * 10, nd * 10});
			ans = min(ans, j / K1 * P1 + val);
		}
	} else {
		for (int j = 0; j <= K1; j++) {
			__int128 nd = T - K2 * j;
			if (nd <= 0) {
				ans = min(ans, j * P2);
				break;
			}
			__int128 rem = nd % K1;
			__int128 val = min({(nd + K1 - 1) / K1 * P1, nd / K1 * P1 + rem * 10, nd * 10});
			ans = min(ans, j * P2 + val);
		}
	}

	swap(K1, K2);
	swap(P1, P2);

	if (K1 >= lim) {
		for (ll j = 0;; j += K1) {
			__int128 nd = T - j;
			if (nd <= 0) {
				ans = min(ans, j / K1 * P1);
				break;
			}
			__int128 rem = nd % K2;
			__int128 val = min({(nd + K2 - 1) / K2 * P2, nd / K2 * P2 + rem * 10, nd * 10});
			ans = min(ans, j / K1 * P1 + val);
		}
	} else {
		for (int j = 0; j <= K1; j++) {
			__int128 nd = T - K2 * j;
			if (nd <= 0) {
				ans = min(ans, j * P2);
				break;
			}
			__int128 rem = nd % K1;
			__int128 val = min({(nd + K1 - 1) / K1 * P1, nd / K1 * P1 + rem * 10, nd * 10});
			ans = min(ans, j * P2 + val);
		}
	}

	ll tans = ans;
	cout << tans << '\n';
}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 1;
	// cin >> t;
	for (int i = 1; i <= t; i++) { solve(); }
	return 0;
}