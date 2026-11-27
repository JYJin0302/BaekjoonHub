#include <bits/stdc++.h>
using namespace std;
using ll = long long;


void solve() {

	int n;
	cin >> n;
	ll c1, c2;
	cin >> c1 >> c2;


	vector<ll> A(n);
	for (auto& i : A) cin >> i;

	ll ans = 0;
	if (c1 <= c2) {

		for (auto i : A) ans += i;
		ans *= c1;
		cout << ans;
		return;
	}

	for (int i = 0; i < n - 2; i++) {
		ll a, b, c;
		a = A[i], b = A[i + 1], c = A[i + 2];

		ll tv = min(a, max(0ll, b - c));

		a -= tv, b -= tv;
		ans += tv * (c1 + c2);

		tv = min({ a, b, c });
		a -= tv, b -= tv, c -= tv;
		ans += tv * (c1 + c2 * 2);

		ans += a * c1;
		A[i + 1] = b, A[i + 2] = c;
	}

	ll a = A[n - 2], b = A[n - 1];

	ll tv = min(a, b);
	a -= tv, b -= tv;

	ans += tv * (c1 + c2) + c1 * a + c1 * b ;
	cout << ans;

}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}

}