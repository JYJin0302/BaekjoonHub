#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b) {
	if (a > b) swap(a, b);
	if (a == 0) return b;
	return gcd(b % a, a);
}
void solve() {
	ll n, a;
	cin >> n >> a;

	// ax = 1 (mod n)
	// ax + ny = 1 (mod n)

	ll vx1, vx2, vy1, vy2, r1, r2;
	vx1 = 1, vy1 = 0, r1 = n;
	vx2 = 0, vy2 = 1, r2 = a;

	if ((n + 1) % a == 0) {
		if ((n + 1) / a <= 1e9) cout << (n + 1) / a << '\n';
		else cout << "IMPOSSIBLE\n";
		return;
	}
	if (n == 1) {
		cout << "1\n";
		return;
	}

	if (gcd(n, a) != 1) {
		cout << "IMPOSSIBLE\n";
		return;
	}

	while (r2 != 0) {

		ll tx, ty, tr;
		ll df = r1 / r2;
		tx = vx2 * df;
		ty = vy2 * df;
		tr = r2 * df;
		tx = vx1 - tx;
		ty = vy1 - ty;
		tr = r1 - tr;

		vx1 = vx2, vy1 = vy2, r1 = r2;
		vx2 = tx, vy2 = ty, r2 = tr;

		//cout << vx1 << ' ' << vy1 << ' ' << r1 << '\n';
	}

	ll ans = (vy1 + n) % n;
	if (ans <= 1e9) cout << ans << '\n';
	else cout << "IMPOSSIBLE\n";

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