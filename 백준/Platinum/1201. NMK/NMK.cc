#include <bits/stdc++.h>
using namespace std;

int main() {

	int n, m, k;
	cin >> n >> m >> k;

	bool sw = 0;
	if (m > k) swap(m, k), sw = 1;

	int minn = (n + m - 1) / m, maxx = n + 1 - m;
	if (k > maxx || k < minn) {
		cout << -1;
		return 0;
	}

	k -= minn;

	vector<int> ans;
	for (int i = 0; i < m; i++) {
		ans.push_back(n + 1 - m + i);
	}

	int c = n - m;
	while (c > 0) {
		int d = min(m - 1, k);
		k -= min(m - 1, k);

		int t = max(1, c - m + 1);
		for (int i = 0; i < d; i++) ans.push_back(c - i);
		for (int i = 0; i < min(m, c) - d; i++) ans.push_back(t + i);

		c -= m;
	}

	if (sw) reverse(ans.begin(), ans.end());
	for (int i : ans)cout << i << ' ';
	cout << '\n';
}