#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int solve(int n) {

	string s = to_string(n);

	int cnt = 0;
	for (auto i : s) {
		int x = int(i - '0');

		if (cnt == 0 && x == 2) cnt++;
		else if (cnt == 1 && x == 0) cnt++;
		else if (cnt == 2 && x == 2) cnt++;
		else if (cnt == 3 && x == 3) cnt++;
	}

	if (cnt == 4) return 1;
	return 0;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	int ans = 0;
	for (int i = 2023; i <= n; i++) {
		ans += solve(i);
	}

	cout << ans;
}