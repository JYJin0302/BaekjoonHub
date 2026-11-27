#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };
// 북 동 남 서

int ansx, ansy, ndx, ndy;
pair<int, int> dirx, diry;


void solve(int sz, int nk) {
	if(sz == 1 || nk == 0) return;

	int tn = sz / 2;

	int ds = nk / (tn * tn);

	switch (ds) {
	case 0:
		swap(dirx, diry);
		ndx = 0;
		ndy = 0;
		break;
	case 1:
		// dy += tn
		ndx = dirx.first * 0 + diry.first * tn;
		ndy = dirx.second * 0 + diry.second * tn;
		break;
	case 2:
		// dx += tn, dy += tn
		ndx = dirx.first * tn + diry.first * tn;
		ndy = dirx.second * tn + diry.second * tn;
		break;
	case 3:
		// dx += sn-1, dy += tn-1
		ndx = dirx.first * (sz-1) + diry.first * (tn-1);
		ndy = dirx.second * (sz-1) + diry.second * (tn-1);

		swap(dirx, diry);
		dirx.first *= -1;
		dirx.second *= -1;
		diry.first *= -1;
		diry.second *= -1;
		break;
	}

	ansx += ndx;
	ansy += ndy;
	nk -= ds * (tn * tn);

	solve(tn, nk);
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	ansx = 1, ansy = 1;
	dirx = { 1, 0 };
	diry = { 0, 1 };

	solve(n, k - 1);

	cout << ansx << ' ' << ansy;
}