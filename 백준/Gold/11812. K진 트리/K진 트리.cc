#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll n, k, q;
	cin >> n >> k >> q;

	if (k == 1) {

		while (q--) {
			ll a, b;
			cin >> a >> b;
			cout << abs(a - b) << '\n';
		}
		return 0;
	}

	vector<pair<ll, ll>> A;
	ll b = 0, a = 1;
	while (b < n) {
		A.push_back({ b + 1, b + a });
		b = b + a, a *= k;
	}

	while (q--) {

		ll a, b;
		cin >> a >> b;

		int da = 0, db = 0;
		while (!(a >= A[da].first && a <= A[da].second)) da++;
		while (!(b >= A[db].first && b <= A[db].second)) db++;

		if (da > db) swap(da, db), swap(a, b);

		int ans = 0;
		while (db != da) {

			ans++;
			ll ta, tb, pa, pb;
			tie(ta, tb) = A[db];
			tie(pa, pb) = A[db - 1];

			b = pa + (b - ta) / k;
			db--;
		}
		
		while (a != b) {
			ans += 2;
			ll ta, tb, pa, pb;
			tie(ta, tb) = A[db];
			tie(pa, pb) = A[db - 1];

			b = pa + (b - ta) / k;
			a = pa + (a - ta) / k;
			db--;
		}

		cout << ans << '\n';
	}
}