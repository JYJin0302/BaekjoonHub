#include <bits/stdc++.h>
using namespace std;

vector<int> seg;

int init(int l, int r, int n) {
	if (l == r) return seg[n];

	int mid = (l + r) / 2;
	int n1 = init(l, mid, n * 2);
	int n2 = init(mid + 1, r, n * 2 + 1);

	if (n1 == 2) n1 = 1;
	if (n2 == 2) n2 = 1;
	return seg[n] = n1 * n2;
}

void update(int l, int r, int n, int c, int t) {
	if (l > c || r < c) return;
	
	if (l == c && r == c) {
		seg[n] = t; return;
	}
	int mid = (l + r) / 2;
	update(l, mid, n * 2, c, t);
	update(mid + 1, r, n * 2 + 1, c, t);
	seg[n] = seg[n * 2] * seg[n * 2 + 1];
}

int subprod(int l, int r, int n, int sl, int sr) {
	if (l > sr || r < sl) return 1;

	if (l >= sl && r <= sr) return seg[n];

	int mid = (l + r) / 2;

	return subprod(l, mid, n * 2, sl, sr) * subprod(mid + 1, r, n * 2 + 1, sl, sr);
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, k, a, b;
	char s;
	while (cin >> n >> k) {
		int size = 1;
		while (size < n) size *= 2;

		seg = vector<int>(size * 2, 2);
		for (int i = 0; i < n; i++) {
			cin >> a;
			if (a > 0) a = 1;
			else if (a < 0) a = -1;
			seg[size + i] = a;
		}

		init(size, size * 2 - 1, 1);

		string ans = "";
		while (k--) {
			cin >> s >> a >> b;
			if (s == 'C') {
				if (b > 0) b = 1;
				else if (b < 0) b = -1;
				
				update(size, size * 2 - 1, 1, size - 1 + a, b);
			}
			else if (s == 'P') {
				int temp = subprod(size, size * 2 - 1, 1, size - 1 + a, size - 1 + b);
				if (temp > 0) ans += '+';
				else if (temp < 0) ans += '-';
				else ans += '0';
			}
		}
		cout << ans << '\n';
	}
}