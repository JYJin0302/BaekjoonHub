#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

__int128 m, a, c, x0, n, g;

vector<__int128> M[77];

vector<__int128> mult(vector<__int128> a1, vector<__int128> a2) {
	vector<__int128> res = {0, 0, 0, 0};
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++) {
				res[i * 2 + j] += a1[i * 2 + k] * a2[k * 2 + j] % m;
				res[i * 2 + j] %= m;
			}
		}
	}

	return res;
}

void solve() {
	ll _m, _a, _c, _x0, _n, _g;

	cin >> _m >> _a >> _c >> _x0 >> _n >> _g;
	m = _m, a = _a, c = _c, x0 = _x0, n = _n, g = _g;

	M[0] = {a % m, 0, c % m, 1};
	for (int i = 1; i < 70; i++) { M[i] = mult(M[i - 1], M[i - 1]); }

	if (n == 0) {
		ll ans = x0 % m % g;
		cout << ans << '\n';
	} else {
		vector<__int128> b = {1, 0, 0, 1};
		for (int j = 0; j < 63; j++) {
			if (n & (1ll << j)) { b = mult(b, M[j]); }
		}

		ll ans = (x0 % m * b[0] + b[2]) % m % g;
		;
		cout << ans << '\n';
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 1;
	// cin >> t;
	while (t--) { solve(); }
	return 0;
}