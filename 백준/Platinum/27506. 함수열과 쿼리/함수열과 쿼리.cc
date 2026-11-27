#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct T {
	vector<int> f;
	T() {
		f = { 0, 1, 2, 3, 4 };
	}

	T operator+(T& other) {
		vector<int> tmp(5);
		
		for (int i = 0; i < 5; i++) {
			tmp[i] = f[other.f[i]];
		}

		T res;
		res.f = tmp;
		return res;
	}

	void pf() {
		for (auto i : f) cout << i + 1 << ' ';
		cout << '\n';
	}
};

vector<T> seg;

void init(int l, int r, int n) {

	if (l == r) return;

	int m = (l + r) / 2;
	init(l, m, n * 2);
	init(m + 1, r, n * 2 + 1);

	seg[n] = seg[n * 2] + seg[n * 2 + 1];
}

void update(int l, int r, int n, int u, T& v) {
	if (l == u && r == u) {
		seg[n] = v;
		return;
	}

	if (l > u || r < u) return;

	int m = (l + r) >> 1;
	update(l, m, n * 2, u, v);
	update(m + 1, r, n * 2 + 1, u, v);
	seg[n] = seg[n * 2] + seg[n * 2 + 1];
}

T ssum(int l, int r, int n, int sl, int sr) {
	if (sl > sr) return T();
	if (l > sr || r < sl) return T();
	if (l >= sl && r <= sr) return seg[n];

	int m = (l + r) / 2;
	T res = ssum(l, m, n * 2, sl, sr);
	T res2 = ssum(m + 1, r, n * 2 + 1, sl, sr);
	return res + res2;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	int sn = 1;
	while (sn < n) sn *= 2;

	seg = vector<T>(sn * 2);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> seg[sn + i].f[j];
			seg[sn + i].f[j]--;
		}
	}

	init(0, sn - 1, 1);

	/*
	cout << "RES: \n";
	for (int i = 1; i < sn * 2; i++) {
		seg[i].pf();
	}
	*/

	int q;
	cin >> q;
	while (q--) {

		int u, a, b;
		vector<int> tmp(5), tdx(5), ans(5), ans2(5);
		cin >> u >> a >> b;
		for (auto& i : tmp) {
			cin >> i;
			i--;
		}

		a--, b--, u--;
		T lft = ssum(0, sn - 1, 1, a, u-1);
		T rgt = ssum(0, sn - 1, 1, u+1, b);

		for (int i = 0; i < 5; i++) {
			tdx[lft.f[i]] = i;
		}

		for (int i = 0; i < 5; i++) {
			ans[i] = tdx[tmp[i]];
		}
		for (int i = 0; i < 5; i++) {
			ans2[rgt.f[i]] = ans[i];
		}

		T rr; 
		rr.f = ans2;
		rr.pf();

		update(0, sn - 1, 1, u, rr);
	}


}