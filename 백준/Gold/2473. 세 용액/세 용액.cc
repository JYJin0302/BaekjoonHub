#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);
	int n;
	cin >> n;

	vector<ll> A(n);
	for (auto& i : A) cin >> i;

	sort(A.begin(), A.end());

	ll ans = 3000000000;

	ll a1 = 0, a2 = 0, a3 = 0;
	for (int i = 0; i < n; i++) {
		ll target = -A[i];

		int l = 0, r = n - 1;
		if (l == i) l++;
		if (r == i) r--;


		ll t2 = -1, t3 = -1;
		ll temp = 3000000001;
		while (l < r) {
			ll curr = A[l] + A[r];

			if (temp > abs(curr - target)) {
				t2 = l;
				t3 = r;
				temp = abs(curr - target);
			}

			if (curr > target) {
				r--;
				if (r == i) r--;
			}
			else {
				l++;
				if (l == i) l++;
			}
		}

		if (ans > temp && t2 != -1 && t3 != -1) {
			a1 = A[i];
			a2 = A[t2];
			a3 = A[t3];
			ans = temp;
		}
	}

	vector<ll> res = { a1, a2, a3 };
	sort(res.begin(), res.end());
	for (ll i : res) cout << i << ' ';
}