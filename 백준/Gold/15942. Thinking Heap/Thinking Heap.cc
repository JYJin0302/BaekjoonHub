#include <bits/stdc++.h>
using namespace std;

int main() {

	int n, k, p;
	cin >> n >> k >> p;

	int lPos = log2(p);

	int gPos = 0;
	int l = p, r = p;
	while (1) {

		if (r <= n) {
			gPos += r - l + 1;
			r = r * 2 + 1;
			l = l * 2;
		}
		else {
			gPos += max(0, n - l + 1);
			break;
		}
	}

	gPos--;

	bool ok = (lPos < k) && (gPos + k <= n);

	if (!ok) cout << -1;
	else {

		vector<int> ans(n + 1);
		vector<bool> used(n + 1);
		used[k] = 1;
		ans[p] = k;
		int tp = p, cnt = 1;
		while (tp / 2) {
			tp /= 2;
			ans[tp] = cnt;
			used[cnt] = 1;
			cnt++;
		}

		cnt = 1;
		int l = p, r = p;
		while (1) {
			l *= 2;
			r = r * 2 + 1;

			if (l > n) break;

			for (int i = l; i <= min(n, r); i++) {
				ans[i] = k + cnt;
				used[k + cnt] = 1;
				cnt++;
			}
		}

		int rr = 1;
		

		for (int i = 1; i <= n; i++) {
			if (ans[i] != 0) continue;
			while (used[rr]) rr++;
			ans[i] = rr;
			used[rr] = 1;
		}

		for (int i = 1; i <= n; i++) cout << ans[i] << ' ';

	}

}