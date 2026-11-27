#include <bits/stdc++.h>
using namespace std;
#define INF 100000000

int n, q, U, V;
// L, R, all, max
vector<tuple<int, int, int, int>> seg;

void init(int l, int r, int n) {
	if (l == r) return;

	int mid = (l + r) / 2;
	init(l, mid, n * 2), init(mid + 1, r, n*2 + 1);

	int la, lb, lc, ld, ra, rb, rc, rd;
	tie(la, lb, lc, ld) = seg[n * 2];
	tie(ra, rb, rc, rd) = seg[n * 2 + 1];

	int a, b, c, d;
	a = max( la, -INF);
	if (lc != -INF && ra != -INF) a = max(a, lc + ra);
	b = max(rb,  -INF);
	if (lb != -INF && rc != -INF) b = max(b, lb + rc);
	c = -INF;
    if (lc != -INF && rc != -INF) c = max(c, lc + rc);
	d = max({ a, b, c, -INF });
	d = max({ d, ld, rd });
	if (lb != -INF && ra != -INF) d = max(d, lb + ra);
	seg[n] = { a, b, c, d };
}

void update(int l, int r, int n, int u, int v) {
	if (l > u || r < u) return;
	if (l == u && r == u) {
		seg[n] = { v, v, v, v };
		return;
	}

	int mid = (l + r) / 2;
	update(l, mid, n * 2, u, v), update(mid + 1, r, n * 2 + 1, u, v);

	int la, lb, lc, ld, ra, rb, rc, rd;
	tie(la, lb, lc, ld) = seg[n * 2];
	tie(ra, rb, rc, rd) = seg[n * 2 + 1];

	int a, b, c, d;
	a = max(la, -INF);
	if (lc != -INF && ra != -INF) a = max(a, lc + ra);
	b = max(rb, -INF);
	if (lb != -INF && rc != -INF) b = max(b, lb + rc);
	c = -INF;
	if (lc != -INF && rc != -INF) c = max(c, lc + rc);
	d = max({ a, b, c, -INF });
	d = max({ d, ld, rd });
	if (lb != -INF && ra != -INF) d = max(d, lb + ra);
	seg[n] = { a, b, c, d };
}

tuple<int, int, int, int> ssum(int l, int r, int n, int sl, int sr) {

	if (l > sr || r < sl) return {-INF, -INF, -INF, -INF };
	if (l >= sl && r <= sr) return seg[n];

	int mid = (l + r) / 2;

	int la, lb, lc, ld, ra, rb, rc, rd;
	tie(la, lb, lc, ld) = ssum(l, mid, n*2, sl, sr);
	tie(ra, rb, rc, rd) = ssum(mid+1, r, n*2+1, sl, sr);

	int a, b, c, d;
	a = max(la, -INF);
	if (lc != -INF && ra != -INF) a = max(a, lc + ra);
	b = max(rb, -INF);
	if (lb != -INF && rc != -INF) b = max(b, lb + rc);
	c = -INF;
	if (lc != -INF && rc != -INF) c = max(c, lc + rc);
	d = max({ a, b, c, -INF });
	d = max({ d, ld, rd });
	if (lb != -INF && ra != -INF) d = max(d, lb + ra);
	return { a, b, c, d };
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> q >> U >> V;

	int size = 1;
	while (size < n) size *= 2;
	
	seg = vector<tuple<int, int, int, int>>(size * 2, { -INF, -INF, -INF, -INF });

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		x = x * U + V;
		seg[size + i] = { x, x, x, x };
	}

	init(size, size * 2 - 1, 1);
    
	while (q--) {

		int c, a, b;
		cin >> c >> a >> b;
		if (c == 0) {
			a--, b--;
			int x, y, w, z;
			tie(x, y, w, z) = ssum(size, size * 2 - 1, 1, size + a, size + b);

			cout << max({ x, y, w, z }) - V << '\n';
		}
		else {
			a--;
			update(size, size * 2 - 1, 1, size + a, b * U + V);
			
		}
	}
}