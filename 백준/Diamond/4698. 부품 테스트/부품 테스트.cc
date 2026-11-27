#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

bool cmp(pair<ll, ll> p1, pair<ll, ll > p2){
	if (p1.y != p2.y) return p1.y < p2.y;
	return p1.x < p2.x;
}

void solve() {
	int n, m;
	cin >> n >> m;

	while (n + m) {
		vector<pair<ll, ll>> A, B;
		for (int i = 0; i < n; i++) {
			ll a, b;
			cin >> a >> b;
			A.push_back(mp(a, b));
		}
		for (int i = 0; i < m; i++) {
			ll a, b;
			cin >> a >> b;
			B.push_back(mp(a, b));
		}

		ll totA = 0, totB = 0;
		for (auto [a, b] : A) totA += a * b;
		for (auto [a, b] : B) totB += a * b;

		sort(all(A), cmp);
		sort(all(B), cmp);

		int ix = m - 1;
		ll res = min(totA, totB);
		ll remA = 0, remB = 0;

		ll sumL = 0, sumR = totB;
		for (auto [a, b] : A) remA += a;

		for (int i = 0; i < n; i++) {
			remA -= A[i].x;
			sumL += A[i].x * A[i].y;

			while (ix >= 0 && B[ix].y >= remA) {
				sumR -= B[ix].x * B[ix].y;
				remB += B[ix].x;
				ix--;
			}

			if (remA == 0 || res / remA >= remB) res = min(res, sumL + sumR + remA * remB);
		}

		swap(A, B);
		swap(n, m);
		remA = 0, remB = 0;
		sumL = 0, sumR = totA;
		for (auto [a, b] : A) remA += a;
		ix = m - 1;
		for (int i = 0; i < n; i++) {
			remA -= A[i].x;
			sumL += A[i].x * A[i].y;

			while (ix >= 0 && B[ix].y >= remA) {
				sumR -= B[ix].x * B[ix].y;
				remB += B[ix].x;
				ix--;
			}

			if (remA == 0 || res / remA >= remB) res = min(res, sumL + sumR + remA * remB);
		}

		cout << (res == totA) << '\n';

		cin >> n >> m;
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 1;
	// cin >> t;
	for (int i = 1; i <= t; i++) {
		// cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}