#include <bits/stdc++.h>
using namespace std;
using ll = long long;


void solve() {

	int n, m;
	cin >> n >> m;

	vector<string> A(n);
	for (auto& i : A) cin >> i;

	int xl = n+1, xr = -1, yl = m+1, yr = -1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (A[i][j] == '#') {
				xl = min(i, xl);
				xr = max(xr, i);
				yl = min(j, yl);
				yr = max(yr, j);
			}
		}
	}

	if (xr == -1) {
		cout << 0 << '\n';
		return;
	}

	int ix = 0, iy = 0, cnt = 0;
	if (A[xl][yl] != '#') {
		cnt++;
		ix = xl, iy = yl;
	}
	if (A[xl][yr] != '#') {
		cnt++;
		ix = xl, iy = yr;
	}
	if (A[xr][yl] != '#') {
		cnt++;
		ix = xr, iy = yl;
	}
	if (A[xr][yr] != '#') {
		cnt++;
		ix = xr, iy = yr;
	}

	if (cnt != 1) {
		cout << "0\n";
		return;
	}

	int tx = ix, ty = iy;
	if (tx == xr) {
		while (tx >= 0 && A[tx][iy] == '.') tx--;
		tx++;
	}
	else {
		while (tx < n && A[tx][iy] == '.') tx++;
		tx--;
	}

	if (ty == yr) {
		while (ty >= 0 && A[ix][ty] == '.') ty--;
		ty++;
	}
	else {
		while (ty < m && A[ix][ty] == '.') ty++;
		ty--;
	}

	if (abs(ix - tx) != abs(iy - ty)) {
		cout << "0\n";
		return;
	}

	int cnt1 = 0, cnt2 = 0;
	for (int i = xl; i <= xr; i++) {
		for (int j = yl; j <= yr; j++) {
			cnt1 += (A[i][j] == '#');
		}
	}

	if (ix > tx) swap(ix, tx);
	if (iy > ty) swap(iy, ty);

	for (int i = ix; i <= tx; i++) {
		for (int j = iy; j <= ty; j++) {
			cnt2 += (A[i][j] == '#');
		}
	}

	if (cnt2 == 0 && cnt1 == pow(xr - xl + 1, 2) - pow(tx - ix + 1, 2)) {
		cout << "1\n";
	}
	else cout << "0\n";

}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}

}