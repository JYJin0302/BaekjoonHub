#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	vector<bool> dp(1000001);
	dp[0] = 0;

	for (int i = 1; i <= 1000000; i++) {
		bool win = 0;
		for (int j = 1; j * j <= i; j++) {
			if (!dp[i - j * j]) {
				win = 1;
				break;
			}
		}
		dp[i] = win;
	}

	int t;
	cin >> t;
	while (t--) {
		int x;
		cin >> x;
		if (dp[x]) cout << "koosaga\n";
		else cout << "cubelover\n";
	}
}