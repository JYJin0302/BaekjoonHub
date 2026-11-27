#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {

	int n;
	cin >> n;

	string s;
	cin >> s;

	if (n == 1 || n == 3) {
		cout << "-1\n";
		return;
	}

	if (n == 2) {
		if (s[0] == s[1]) cout << "1\n";
		else cout << "0\n";
		return;
	}

	int tmp = 0;
	int ans = 0;
	int ans1 = 0, ans2 = 0;
	string ts = s;
	if (s[0] == s[n - 1]) {
		tmp = 1;

		s[0] = ('0' + '1' - s[0]);
		ts[n - 1] = ('0' + '1' - ts[n - 1]);
	}

	int l = 1, r = n - 2;

	while (1) {
		if (s[l] == s[0] && s[r] == s[n - 1]) {
			l++, r--;
		}
		else break;
	}

	if (r == l) ans1 = 2 + tmp;
	else {
		ans1 += (s[r] != s[0]);
		ans1 += (s[l] != s[n - 1]);
		ans1 += tmp;
	}

	swap(s, ts);
	l = 1, r = n - 2;

	while (1) {
		if (s[l] == s[0] && s[r] == s[n - 1]) {
			l++, r--;
		}
		else break;
	}
	if (r == l) ans2 = 2 + tmp;
	else {
		ans2 += (s[r] != s[0]);
		ans2 += (s[l] != s[n - 1]);
		ans2 += tmp;
	}

	cout << min(ans1, ans2) << '\n';

}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}