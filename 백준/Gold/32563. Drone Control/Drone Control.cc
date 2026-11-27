#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

const ld eps = 1e-8;

void solve() {
	ld p, r, y;
	cin >> p >> r >> y;

	ld n, e, w, s;

	array<ld, 4> ans = {0, 0, 0, 0};
	ld L = 0, R = 10;
	while (R - L > eps) {
		ld m = (L + R) / 2;

		vector<pair<ld, ld>> rn(4);
		rn[0] = mp(-m, m);
		rn[1] = mp(-m + r, m + r);
		ld c1 = (p + r + y) / 2;
		rn[2] = mp(-m + c1, m + c1);
		c1 = (y + r - p) / 2;
		rn[3] = mp(-m + c1, m + c1);

		ld tl = -m, tr = m;
		for (auto [a, b] : rn) {
			tl = max(tl, a);
			tr = min(tr, b);
		}
		if (tl <= tr + eps) {
			R = m;

			n = tl, s = n - r;
			e = (p + r + y - 2 * tl) / 2;
			w = (r + y - p - 2 * tl) / 2;
			ans = {n, e, s, w};
		} else {
			L = m;
		}
	}

	cout << fixed << setprecision(20);
	for (int i = 0; i < 4; i++) cout << ans[i] << ' ';
	cout << '\n';
}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 1;
	cin >> t;
	while (t--) { solve(); }
	return 0;
}