#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> seg;
vector<ll> lazy;

void init(int l, int r, int n) {

	if (l == r) return;
	
	int mid = (l + r) / 2;
	init(l, mid, n * 2);
	init(mid + 1, r, n * 2 + 1);
	seg[n] = seg[n * 2] + seg[n * 2 + 1];
}

void update(int l, int r, int n, int ul, int ur, int v) {

	if (l > ur || r < ul) return;
	if (l >= ul && r <= ur) {
		lazy[n] += v;
		return;
	}

	int mid = (l + r) / 2;
	update(l, mid, n * 2, ul, ur, v);
	update(mid + 1, r, n * 2 + 1, ul, ur, v);
}

void cal(int l, int r, int n, int c) {

	if (lazy[n] != 0) {
		if (l != r) {
			lazy[n * 2] += lazy[n];
			lazy[n * 2 + 1] += lazy[n];
		}
		else {
			seg[n] += lazy[n];
		}
		lazy[n] = 0;
	}

	if (l > c || r < c) return;
	if (l == c && r == c) return;

	int mid = (l + r) / 2;
	cal(l, mid, n * 2, c), cal(mid + 1, r, n * 2 + 1, c);
	seg[n] = seg[n * 2] + seg[n * 2 + 1];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;

	int size = 1;
	while (size < n) size *= 2;

	seg = vector<ll>(size * 2);
	lazy = vector<ll>(size * 2);

	for (int i = 0; i < n; i++) {
		cin >> seg[size + i];
	}

	init(size, size * 2 - 1, 1);

	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int t;
		cin >> t;
		if (t == 1) {
			int a, b, v;
			cin >> a >> b >> v;

			update(size, size * 2 - 1, 1, size + a - 1, size + b - 1, v);
		}
		else {
			int v;
			cin >> v;

			cal(size, size * 2 - 1, 1, size + v - 1);
			cout << seg[size + v - 1] << '\n';
		}
	}
}