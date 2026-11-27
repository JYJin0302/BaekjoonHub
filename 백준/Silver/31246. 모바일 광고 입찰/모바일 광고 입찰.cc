#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	vector<ll> A(n), B(n);
	for (int i = 0; i < n; i++) {
		cin >> A[i] >> B[i];
	}

	ll l = 0, r = 1e9, ans = 0;
	while (l <= r) {
		ll m = (l + r) >> 1;

		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (A[i] + m >= B[i]) cnt++;
		}

		if (cnt >= k) {
			ans = m;
			r = m - 1;
		}
		else l = m + 1;
	}
	cout << ans;

}