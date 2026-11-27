#include <bits/stdc++.h>
using namespace std;

vector<int> seg;

void init(int l, int r, int n) {
	if (l == r) return;

	int mid = (l + r) / 2;
	init(l, mid, n * 2);
	init(mid + 1, r, n * 2 + 1);
	seg[n] = seg[n * 2] + seg[n * 2 + 1];
}

int search(int l, int r, int n, int cnt) {

	if (l == r) {
		return r;
	}

	int mid = (l + r) / 2;

	if (seg[n * 2] < cnt) {
		return search(mid + 1, r, n * 2 + 1, cnt - seg[n * 2]);
	}
	else return search(l, mid, n * 2, cnt);
}

void update(int l, int r, int n, int u) {

	if (l > u || r < u) return;
	if (l == u && r == u) {
		seg[n] = 0;
		return;
	}

	int mid = (l + r) / 2;
	update(l, mid, n * 2, u);
	update(mid + 1, r, n * 2 + 1, u);
	seg[n] = seg[n * 2] + seg[n * 2 + 1];

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
		int x;
		cin >> x;
		seg[size + i] = x;
	}

	init(size, size * 2 - 1, 1);

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;

		int k = search(size, size * 2 - 1, 1, x) - size;
		cout << k+1 << ' ';
		update(size, size * 2 - 1, 1, size + k);
	}
}