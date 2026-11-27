#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, q;
	cin >> n >> m >> q;

	vector<int> A(n+1);
	for (int i = 1; i <= n; i++) cin >> A[i];

	int l = 0, r = A[n] - A[1], ans = 0;
	while (l <= r) {

		int md = (l + r) >> 1;
		//cout << "CURR: " << md << '\n';

		vector<int> valid(n+1);
		valid[0] = 1;

		int ix = 1, lft = 1;
		while (ix <= n) {
			
			while (A[ix] - A[lft] > md) lft++;
			int rft = ix - m;

			//cout << ix << ' ' << lft << ' ' << rft << '\n';

			int vv = -1;
			if (rft >= 0) vv = valid[rft];
			if (lft > 1) vv -= valid[lft - 2];
			if (vv > 0) valid[ix] = 1;
			if (rft >= lft - 1 && lft == 1) valid[ix] = 1;

			valid[ix] += valid[ix - 1];
			ix++;
		}
		if (valid[n] - valid[n - 1]) {
			// ok
			ans = md;
			r = md - 1;
		}
		else l = md + 1;

		/*cout << "RES: " << md << '\n';
		for (auto i : valid) cout << i << ' ';
		cout << '\n';*/
	}
	//cout << "ANS: " << ans << '\n';
	while (q--) {
		int x;
		cin >> x;

		if (x >= ans) cout << 1;
		else cout << 0;
	}
}