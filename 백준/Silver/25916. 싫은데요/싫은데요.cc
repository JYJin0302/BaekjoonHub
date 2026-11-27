#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mod = 998244353;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n, m;
	cin >> n >> m;

	vector<ll> A(n);
	for (auto& i : A) cin >> i;

	int l = 0, r = 0;
	ll val = 0;
	ll ans = 0;
	while (l < n) {

		while (r < n && val <= m) {
			ans = max(ans, val);
			val += A[r];
			r++;
		}

		if (val <= m) ans = max(ans, val);

		val -= A[l];
		l++;
	}

	cout << ans;
}