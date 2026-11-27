#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

void solve() {
	int n;
	cin >> n;

	ll a0 = 0, b0 = 0, c0 = 0;
	ll pre = 0;
	bool ok = 1;
	for (int i = 0; i < n; i++) {
		ll a, b, c, p;
		cin >> a >> b >> c >> p;

		ll t = p - pre;
		ll nd = max(0ll, a - a0) + max(0ll, b - b0) + max(0ll, c - c0) + 1;
		if (nd <= t) {
			pre += nd;
			a0 = max(a0, a);
			b0 = max(b0, b);
			c0 = max(c0, c);
		} else {
			ok = 0;
		}
	}
	if (ok) cout << "YES\n";
	else cout << "NO\n";
}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 1;
	cin >> t;
	while (t--) { solve(); }
	return 0;
}