#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, k;
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

int A[111][111], tmp[111][111];

bool inGrid(int x, int y) {
	return x >= 0 && x < n&& y >= 0 && y < n;
}

void pf() {
	/*
	cout << "CURR: \n";
	for (int h = 100; h >= 0; h--) {
		bool ok = 0;
		for (int i = 0; i < n; i++) {
			if (A[h][i]) ok = 1;
		}

		if (!ok) continue;

		for (int i = 0; i < n; i++) {
			if (A[h][i] == 0) cout << "   ";
			else if (A[h][i] < 10) cout << ' ' << A[h][i] << ' ';
			else cout << A[h][i] << ' ';
		}
		cout << '\n';
	}
	*/
}

bool finish_check() {
	int mx = 10001, Mx = -1;
	for (int i = 0; i < n; i++) {
		mx = min(mx, A[0][i]);
		Mx = max(Mx, A[0][i]);
	}

	return Mx - mx <= k;
}

void update() {

	memset(tmp, 0, sizeof(tmp));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (A[i][j] == 0) continue;

			for (int k = 0; k < 4; k++) {
				int ni = i + dx[k];
				int nj = j + dy[k];

				if (inGrid(ni, nj) && A[ni][nj] != 0) {
					int df = (A[ni][nj] - A[i][j]) / 5;
					tmp[i][j] += df;
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			A[i][j] += tmp[i][j];
		}
	}

	pf();
}

void move0() {

	int ix = 0, h = 0;
	while (A[h][ix] == 0) ix++;

	for (int j = 0; j < n; j++) {
		A[0][j] = A[h][ix];
		if (h > 0) A[h][ix] = 0;

		if (A[h + 1][ix] != 0) h++;
		else {
			ix++, h = 0;
		}
	}

	pf();

}

void move1(int l, int r) {
	int h = 0;
	while (A[h][l] != 0) h++;
	h--;

	if (h+1 > n-1 - r) return;


	int nl = r+1;
	int nr = nl + h;

	for (int i = r; i >= l; i--) {
		for (int j = 0; j <= h; j++) {
			A[r - i+1][nl + j] = A[j][i];
			A[j][i] = 0;
		}
	}

	pf();
	move1(nl, nr);
}

void move2(int l, int r, int cnt = 0) {

	if (cnt == 2) return;


	int md = (l + r) >> 1;
	int nl = md + 1;
	int h = 0, th= 0;
	int len = nl - l - 1;

	while (A[th][l]) th++;

	while (A[h][l]) {
		for (int i = l; i <= md; i++) {
			A[th][nl + len - (i - l)] = A[h][i];
			A[h][i] = 0;
		}

		h++, th++;
	}

	if (cnt == 1) {
		for (int i = nl; i <= r; i++) {
			swap(A[2][i], A[3][i]);
		}
	}

	pf();
	move2(nl, r, cnt + 1);

}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> A[0][i];
	}


	int ans = 0;
	while (!finish_check()) {
		ans++;
		// add minimum
		int mx = 10001;
		for (int i = 0; i < n; i++) {
			mx = min(mx, A[0][i]);
		}
		for (int i = 0; i < n; i++) {
			if (A[0][i] == mx) A[0][i]++;
		}

		move1(0, 0);

		update();

		move0();

		move2(0, n - 1);

		update();

		move0();
	}

	cout << ans;
}