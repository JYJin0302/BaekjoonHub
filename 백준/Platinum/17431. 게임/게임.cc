#include <bits/stdc++.h>
using namespace std;


void solve() {

	int n;
	cin >> n;

	int ans = 1;
	int ans_tot = n - 1;

	for (int i = 2; i <= n / 2; i++) {

		int a = n, b = i, tot = 0;
		// 마지막 상태

		bool ok = 1;
		while (b != 1) {

			if (a % b == 0) {
				ok = 0;
				break;
			}
			tot += a / b;
			a %= b;
			swap(a, b);
		}

		if (!ok) continue;
		tot += a - 1;

		if (tot < ans_tot) {
			ans_tot = tot;
			ans = i;
		}
	}


	int a = n, b = ans;
	vector<int> tmp;
	while (b != 1) {
		tmp.push_back(a / b);
		a %= b;
		swap(a, b);
	}
	tmp.push_back(a - 1);

	bool p = 0;
	for (int i = tmp.size() - 1; i >= 0; i--) {
		if (!p) cout << string(tmp[i], 'R');
		else cout << string(tmp[i], 'B');
		p ^= 1;
	}
	cout << '\n';


}
int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		solve();
	}

}