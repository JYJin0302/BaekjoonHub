#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct T {
	ll x, y;
};

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	cout << fixed << setprecision(10);

	ll n, k;
	cin >> n >> k;

	vector<T> A(n);
	for (auto& i : A) cin >> i.x >> i.y;

	long double l = 0, r = 1;
	while (r - l >= 1e-9) {

		long double md = (l + r) / 2;

		vector<long double> tmp(n);
		for (int i = 0; i < n; i++) {
			tmp[i] = md * A[i].y - A[i].x;
		}

		long double tt = 0;

		sort(tmp.begin(), tmp.end());
		for (int i = 0; i < k; i++) tt += tmp[i];

		if (tt <= 0) l = md;
		else r = md;
	}
	cout << l;
}