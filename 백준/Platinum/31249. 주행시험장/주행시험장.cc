#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair

void solve() {
    ll a, b;
	cin >> a >> b;

	if (a > b) swap(a, b);

	if (a == b) {
		cout << a << ' ' << 3 << '\n';
		return;
	}
	if (b <= a * 2) {
		cout << a << ' ' << 7 << '\n';
		return;
	}
	if (b <= (a + 1) * 2) {
		ll cnt = 7;
		if (b - 1 <= a + 1) cnt = 5;
		cout << a + 1 << ' ' << cnt << '\n';
		return;
	}
	ll cnt = 4;
	ll nd = b - a - 1 - (a + 1);
	cnt += nd * 2;
	cnt += 3;
	cout << a + 1 << ' ' << cnt << '\n';
	

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}