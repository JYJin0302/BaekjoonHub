#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

void solve() {
	int n, k;
	cin >> n >> k;

	ll tot = 0;
	vector<pair<ll, ll>> A;
	for (int i = 0; i < k; i++) {
		int c, a;
		cin >> c >> a;

		if (c & 1) {
			A.push_back(mp((c + 1) / 2, a));
		} else {
			tot -= a;
			A.push_back(mp(c / 2 + 1, a));
		}
	}

	sort(all(A), [&](pair<ll, ll> p1, pair<ll, ll> p2) { return p1.x * p2.y < p1.y * p2.x; });

	ll S = 0;
	for (auto [a, b] : A) S += b;
	ll cur = 0;
	for (auto [a, b] : A) {
		cur += a;
		tot += 2 * a * S;
		S -= b;
	}
	cout << tot << '\n';
}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 1;
	// cin >> t;
	for (int i = 1; i <= t; i++) { solve(); }
	return 0;
}