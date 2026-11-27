#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    
	int limit = 25;
	vector<int> dp(limit);
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 5;
	for (int i = 3; i < limit; i++) {
		for (int j = 0; j < i; j++) {
			if (i - j == 1) {
				dp[i] += dp[j];
			}
			else if (i - j == 2) dp[i] += 4*dp[j];
			else {
				dp[i] += ((i - j) % 2 == 1 ? 2 : 3) * dp[j];
			}
		}
	}
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		cout << dp[n] << '\n';
	}
}