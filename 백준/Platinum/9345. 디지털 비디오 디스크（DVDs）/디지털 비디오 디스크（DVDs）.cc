#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000

vector<int> segM, segm;  // Max, min

void init(int l, int r, int n) {
	if (l == r) return;

	int mid = (l + r) / 2;
	init(l, mid, n * 2);
	init(mid + 1, r, n * 2 + 1);
	segM[n] = max(segM[n * 2], segM[n * 2 + 1]);
	segm[n] = min(segm[n * 2], segm[n * 2 + 1]);
}

void update(int l, int r, int n, int u) {

	if (l > u || r < u) return;
	if (l == u && r == u) return;

	int mid = (l + r) / 2;
	update(l, mid, n * 2, u);
	update(mid + 1, r, n * 2 + 1, u);

	segM[n] = max(segM[n * 2], segM[n * 2 + 1]);
	segm[n] = min(segm[n * 2], segm[n * 2 + 1]);
}

int maxV(int l, int r, int n, int sl, int sr) {

	if (l > sr || r < sl) return -1;
	if (l >= sl && r <= sr) return segM[n];

	int mid = (l + r) / 2;
	return max(maxV(l, mid, n * 2, sl, sr), maxV(mid + 1, r, n * 2 + 1, sl, sr));
}

int minV(int l, int r, int n, int sl, int sr) {

	if (l > sr || r < sl) return INF;
	if (l >= sl && r <= sr) return segm[n];

	int mid = (l + r) / 2;
	return min(minV(l, mid, n * 2, sl, sr), minV(mid + 1, r, n * 2 + 1, sl, sr));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {

		int n, k;
		cin >> n >> k;

		int size = 1;
		while (size < n) size *= 2;
		segM = vector<int>(size * 2, -1);
		segm = vector<int>(size * 2, n);

		for (int i = 0; i < n; i++) {
			segM[size + i] = i;
			segm[size + i] = i;
		}

		init(size, size * 2 - 1, 1);

		for (int i = 0; i < k; i++) {

			int tt, a, b;
			cin >> tt >> a >> b;
			if (tt == 0) {

				swap(segM[size + a], segM[size + b]);
				swap(segm[size + a], segm[size + b]);
				update(size, size * 2 - 1, 1, size + a);
				update(size, size * 2 - 1, 1, size + b);
			}
			else {

				int MM = maxV(size, size * 2 - 1, 1, size + a, size + b);
				int mm = minV(size, size * 2 - 1, 1, size + a, size + b);
				if (MM == b && mm == a) cout << "YES\n";
				else cout << "NO\n";
			}
		}

	}
}