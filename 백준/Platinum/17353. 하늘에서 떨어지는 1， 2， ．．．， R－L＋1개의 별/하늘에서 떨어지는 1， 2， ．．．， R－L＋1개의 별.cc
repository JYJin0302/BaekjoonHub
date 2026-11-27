#include <bits/stdc++.h>
using namespace std;
using ll = long long;


vector<ll> seg;
vector<pair<ll, ll>> lazy;

pair<ll, ll> addp(pair<ll, ll> p1, pair<ll, ll> p2) {
	return { p1.first + p2.first, p1.second + p2.second };
}

void update(int l, int r, int n, int ul, int ur, int v) {
	if (l > ur || r < ul) return;
	if (l >= ul && r <= ur) {
		pair<ll, ll> t = { v, v + ur - ul };
		lazy[n] = addp(lazy[n], t);
		return;
	}

	int mid = (l + r) / 2;

	if (mid < ul || mid >= ur) {
		update(l, mid, n * 2, ul, ur, v);
		update(mid + 1, r, n * 2 + 1, ul, ur, v);
	}
	else {

		update(l, mid, n * 2, ul, mid, v);
		update(mid + 1, r, n * 2 + 1, mid+1, ur, v + mid - ul + 1);

	}
}

void solve(int l, int r, int n, int v) {

	if (lazy[n].first != 0) {
		if (l == r) seg[n] += lazy[n].first;
		else {
			
			ll t = (lazy[n].second - lazy[n].first) / ((ll)r - l);
			ll mid = (r - l + 1) / 2;
			lazy[n * 2] = addp(lazy[n * 2], { lazy[n].first , lazy[n].first + t * (mid - 1) });
			lazy[n * 2 + 1] = addp(lazy[n * 2 + 1], { lazy[n].first + t * mid, lazy[n].second });
		}
		lazy[n] = { 0, 0 };
	}

	if (l > v || r < v) return;
	if (l == v && r == v) return;
	int mid = (l + r) / 2;
	solve(l, mid, n * 2, v);
	solve(mid + 1, r, n * 2 + 1, v);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;

	int size = 1;
	while (size < n) size *= 2;

	seg = vector<ll>(size * 2);
	lazy = vector<pair<ll, ll>>(size * 2);

	for (int i = 0; i < n; i++) {
		cin >> seg[size + i];
	}

	int q;
	cin >> q;
	while (q--) {
		int t, a, b;
		cin >> t;
		if (t == 1) {
			cin >> a >> b;
			a--, b--;
			update(size, size * 2 - 1, 1, size + a, size + b, 1);
		}
		else {
			cin >> a;
			a--;
			solve(size, size * 2 - 1, 1, size + a);
			cout << seg[size + a] << '\n';
		}
	}
}