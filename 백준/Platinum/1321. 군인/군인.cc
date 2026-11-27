#include <bits/stdc++.h>
using namespace std;


int ans;
vector<int> seg;

void init(int l, int r, int n) {

	if (l == r) return;

	int mid = (l + r) / 2;
	init(l, mid, n * 2);
	init(mid + 1, r, n * 2 + 1);
	seg[n] = seg[n * 2] + seg[n * 2 + 1];
}

void update(int l, int r, int n, int u, int v) {

	if (l > u || r < u) return;
	if (l == u && r == u) {
		seg[n] += v;
		return;
	}

	int mid = (l + r) / 2;
	update(l, mid, n * 2, u, v);
	update(mid + 1, r, n * 2 + 1, u, v);

	seg[n] = seg[n * 2] + seg[n * 2 + 1];
}

void search(int l, int r, int n, int k) {

	if (l == r) {
		ans = n;
		return;
	}

	int mid = (l + r) / 2;
	int s1 = seg[n * 2], s2 = seg[n * 2 + 1];

	if (s1 >= k) search(l, mid, n * 2, k);
	else search(mid + 1, r, n * 2 + 1, k - s1);
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;

	int size = 1;
	while (size < n) size *= 2;
	seg = vector<int>(size * 2);

	for (int i = 0; i < n; i++) {
		cin >> seg[size + i];
	}

	init(size, size * 2 - 1, 1);

	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {

		int a, b, c;
		cin >> a >> b;

		if (a == 1) {
			cin >> c;

			b--;
			update(size, size * 2 - 1, 1, size + b, c);
		}
		else {

			ans = 0;
			search(size, size * 2 - 1, 1, b);

			cout << ans - size + 1 << '\n';

		}
	}
}