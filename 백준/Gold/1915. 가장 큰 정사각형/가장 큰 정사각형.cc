#include <bits/stdc++.h>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, ans = 0;
	cin >> n >> m;
	vector<vector<int>> base(n ,vector<int>(m));

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			base[i][j] = s[j] - '0';
		}
	}


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i == 0 || j == 0 || base[i][j] == 0) ans = max(ans, base[i][j]);
			else {
				base[i][j] = min({ base[i - 1][j], base[i][j - 1], base[i - 1][j - 1] }) + 1;
				ans = max(base[i][j], ans);
			}
		}
	}

	cout << ans * ans;
}