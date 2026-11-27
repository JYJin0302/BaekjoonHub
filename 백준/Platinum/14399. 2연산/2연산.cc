#include <bits/stdc++.h>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	string ans(n-1, 'X');

	for (int i = 1; i <= n/2; i++) {

		string tmp;
		int a = n - i, b = i;
		// 마지막 상태

		bool ok = 1, p = 0;

		// p = 0 : a > b, 1 : a < b
		while (b != 1) {

			if (a % b == 0) {
				ok = 0;
				break;
			}

			for (int j = 0; j < a / b; j++) {
				if (p) tmp += 'X';
				else tmp += 'Y';
			}

			a %= b;
			if (a < b) {
				p ^= 1;
				swap(a, b);
			}
		}

		if (!ok) continue;

		for (int j = 0; j < a-1; j++) {
			if (p) tmp += 'X';
			else tmp += 'Y';
		}

		reverse(tmp.begin(), tmp.end());
		if (tmp[0] == 'Y') {
			for (int j = 0; j < tmp.size(); j++) {
				tmp[j] = char('Y' + 'X' - tmp[j]);
			}
		}

		tmp += 'X';

		if (tmp.size() < ans.size() || (tmp.size() == ans.size() && tmp < ans)) ans = tmp;
	}
	cout << ans;

}