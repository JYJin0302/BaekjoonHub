#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> A;
vector<int> seg;
int ai = -1;

void init(int l, int r, int n) {
	if (l == r) return;
	int m = (l + r) / 2;
	init(l, m, n * 2);
	init(m + 1, r, n * 2 + 1);

	if (A[seg[n * 2]] <= A[seg[n * 2 + 1]]) seg[n] = seg[n * 2];
	else seg[n] = seg[n * 2 + 1];
}

int mS(int l, int r, int n, int sl, int sr) {
	if (l > sr || r < sl) return -1;
	if (l >= sl && r <= sr) return seg[n];

	int m = (l + r) / 2;
	int t1 = mS(l, m, n * 2, sl, sr), t2 = mS(m + 1, r, n * 2 + 1, sl, sr);

	if (t1 == -1) return t2;
	if (t2 == -1) return t1;

	if (A[t1] <= A[t2]) return t1;
	return t2;
}



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	int sn = 1;
	while (sn < n) sn *= 2;

	seg = vector<int>(sn * 2);
	for (int i = 0; i < sn; i++) seg[sn+i] = i;

	A =vector<int> (sn, 1e9);
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		A[i] = (x - 20) / 10;
	}

	init(0, sn - 1, 1);

	ll ans = 0, anscnt = 0;

	queue<tuple<int, int, int>> q;
	q.push({ 0, n - 1 , 0});
	while (!q.empty()) {

		int a, b, c;
		tie(a, b, c) = q.front();
		q.pop();

		if (b < a) continue;

		int mm = mS(0, sn - 1, 1, a, b);

		int tv = A[mm] - c;
		int tans = tv / 4 + (tv % 4 != 0);
		anscnt += tans;
		ans += tv;
		
		q.push({ a, mm - 1, A[mm] });
		q.push({ mm + 1, b, A[mm] });
	}

	cout << ans*20 << ' ' << anscnt*4;
}