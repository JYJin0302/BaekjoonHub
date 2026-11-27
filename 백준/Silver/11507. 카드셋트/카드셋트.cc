#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;
	cin >> s;

	vector<int> ans(4, 13);  // P, K, H, T
	map<string, bool> cnt;

	int n = s.size() / 3;

	bool ok = 1;
	for (int i = 0; i < n; i++) {
		string st = s.substr(i * 3, 3);

		if (cnt[st]) ok = 0;
		cnt[st] = 1;
		char c = st[0];
		switch (c) {
		case 'P':
			ans[0]--;
			break;
		case 'K':
			ans[1]--;
			break;
		case 'H':
			ans[2]--;
			break;
		case 'T':
			ans[3]--;
			break;
		}
	}

	if (!ok) cout << "GRESKA";
	else cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << ' ' << ans[3];

}