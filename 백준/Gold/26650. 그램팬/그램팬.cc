#include <bits/stdc++.h>
using namespace std;
using ll = long long;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;

	int n = s.size();
	int l = 0, r = 0;
	int tcnt = 0;

	while (l < n && s[l] != 'A') l++;
	r = l;

	ll ans = 0;
	while (l < n) {

		ll lcnt = 0;
		while (r < n && s[r] == 'A') {
			lcnt++;
			r++;
		}
		tcnt = 1;
		while (r < n && tcnt < 26) {

			int tx = s[r] - 'A';
			if (tx == tcnt - 1) r++;
			else if (tx == tcnt) {
				tcnt++;
				r++;
			}
			else break;
		}

		if (tcnt == 26) {
			ll rcnt = 1;
			while (r < n && s[r] == 'Z') rcnt++, r++;

			ans += rcnt * lcnt;
		}
		l = r;
		while (l < n && s[l] != 'A')l++;
		r = l;
	}

	cout << ans;
}