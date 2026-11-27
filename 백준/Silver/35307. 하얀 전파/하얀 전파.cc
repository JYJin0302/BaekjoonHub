#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

void solve() {
	ll n, m, l, r, u, d;
	cin >> n >> m >> l >> r >> u >> d;

	ll ans = n * m;
	ll ansT = 0;
	if (l + r == 0) {
		ans /= m;
	} else {
		ansT += (m - 1 + l + r - 1) / (l + r);
	}

	if (u + d == 0) {
		ans /= n;
	} else {
		ansT += (n - 1 + u + d - 1) / (u + d);
	}
	cout << ans << ' ' << ansT << '\n';
}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 1;
	 cin >> t;
	for (int i = 1; i <= t; i++) { solve(); }
	return 0;
}