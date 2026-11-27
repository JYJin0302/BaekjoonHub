#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {

	string s;
	cin >> s;

	int n = s.size();

	vector<ll> cnt(10);
	if (n == 1) {
		for (int i = 0; i <= 9; i++) {
			if (i >= 1 && i <= s[0] - '0') cout << 1 << ' ';
			else cout << 0 << ' ';
		}
		return 0;
	}

	for (int i = 0; i < n; i++) {

		int d = s[i] - '0';

		if (i == 0) {
			
			ll k = stoll(s.substr(1, n - 1));
			cnt[d] += k + 1;

			for (int j = 1; j < d; j++) {
				cnt[j] += pow(10, n - 1);
			}
		}
		else if (i == n - 1) {

			ll k = stoll(s.substr(0, n - 1));

			for (int j = 9; j > d; j--) {
				cnt[j] += k;
			}
			for (int j = d; j >= 0; j--) {
				cnt[j] += k + 1;
			}
			cnt[0]--;
		}
		else {

			ll L = stoll(s.substr(0, i));
			ll R = stoll(s.substr(i + 1, n));

			for (int j = 9; j > d; j--) {
				cnt[j] += powl(10, n - i - 1) * L;
			}
			cnt[d] += R + 1 + powl(10, n - i - 1) * L;

			for (int j = d - 1; j >= 0; j--) {
				cnt[j] += powl(10, n - i - 1) * (L + 1);
			}
			cnt[0] -= powl(10, n - i - 1);

		}
	}

	for (int i = 0; i <= 9; i++) cout << cnt[i] << ' ';
	cout << '\n';

}