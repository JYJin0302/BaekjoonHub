#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()


int seg[1202020];  // max
int lazy[1202020];

void goLazy(int l, int r, int n) {
	if (lazy[n]) {
		seg[n] += lazy[n];
		if (l != r) {
			lazy[n * 2] += lazy[n];
			lazy[n * 2 + 1] += lazy[n];
		}
		lazy[n] = 0;
	}
}

void init(int l, int r, int n) {
	if (l == r) {
		seg[n] = l;
		return;
	}
	int md = (l + r) >> 1;
	init(l, md, n * 2);
	init(md + 1, r, n * 2 + 1);
	seg[n] = max(seg[n * 2], seg[n * 2 + 1]);
}

void update(int l, int r, int n, int sl, int sr, int val) {
	goLazy(l, r, n);
	if (l > sr || r < sl) return;
	if (l >= sl && r <= sr) {
		lazy[n] += val;
		goLazy(l, r, n);
		return;
	}

	int md = (l + r) >> 1;
	update(l, md, n * 2, sl, sr, val);
	update(md + 1, r, n * 2 + 1, sl, sr, val);
	seg[n] = max(seg[n * 2], seg[n * 2 + 1]);
}

int getIdx(int l, int r, int n, int val) {  // val 이상의 가장 왼쪽 index
	goLazy(l, r, n);
	if (seg[n] < val) return r + 1;
	if (l == r) return l;
	int md = (l + r) >> 1;
	int res = getIdx(l, md, n * 2, val);
	if (res == md + 1) { return getIdx(md + 1, r, n * 2 + 1, val); }
	return res;
}

int cnt[303030];
vector<pair<int, int>> upd[303030];

int fw[303030];
void update(int ix, int val) {
	ix++;
	while (ix <= 300030) {
		fw[ix] += val;
		ix += ix & -ix;
	}
}
int getS(int ix) {
	ix++;
	int res = 0;
	while (ix) {
		res += fw[ix];
		ix -= ix & -ix;
	}
	return res;
}

void solve() {
	int n;
	cin >> n;

	vector<int> A(n), B(n);
	for (auto& i : A) cin >> i;
	for (auto& i : B) cin >> i;


	int tn = 300010;
	init(0, tn - 1, 1);

	int m;
	cin >> m;

	vector<array<int, 3>> Q(m);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;

		a = getIdx(0, tn - 1, 1, a);
		b = getIdx(0, tn - 1, 1, b + 1) - 1;
		Q[i] = {a, b, i};

		if (a == 0) a = getIdx(0, tn - 1, 1, 1);
		update(0, tn - 1, 1, a, b, -1);
	}

	for (auto f : A) cnt[f]++;
	for (auto f : B) cnt[f]++;

	for (int j = 1; j <= 300000; j++) cnt[j] += cnt[j - 1];

	for (int j = 1; j < n; j++) {
		int a = A[j - 1], b = A[j];
		if (a > b) swap(a, b);
		upd[0].push_back(mp(b, 1));
		upd[a + 1].push_back(mp(b, -1));

		a = B[j - 1], b = B[j];
		if (a > b) swap(a, b);
		upd[0].push_back(mp(b, 1));
		upd[a + 1].push_back(mp(b, -1));
	}
	for (int j = 0; j < n; j++) {
		int a = A[j], b = B[j];
		if (a > b) swap(a, b);
		upd[0].push_back(mp(b, 1));
		upd[a + 1].push_back(mp(b, -1));
		if (j) {
			int a = A[j - 1], b = B[j - 1];
			int c = A[j], d = B[j];
			if (a > b) swap(a, b);
			if (c > d) swap(c, d);

			a = min(a, c);
			b = max(b, d);
			upd[0].push_back(mp(b, -1));
			upd[a + 1].push_back(mp(b, 1));
		}
	}

	vector<int> ans(m);
	sort(all(Q));

	int cur = 0;
	for (auto f : Q) {
		while (cur <= f[0]) {
			for (auto [a, b] : upd[cur]) {
				update(a, b);
			}
			cur++;
		}

		int l = f[0], r = f[1], idx = f[2];
		int res = cnt[r] - (l ? cnt[l - 1] : 0);
		int res2 = getS(r) - (l ? getS(l - 1) : 0);
		ans[idx] = res - res2;
		//cout << f[0] << ' ' << f[1] << " => " << res << ' ' << res2 << '\n';
	}

	for (auto f : ans) cout << f << '\n';
}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 1;
	// cin >> t;
	while (t--) { solve(); }
	return 0;
}