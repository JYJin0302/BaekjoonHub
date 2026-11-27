#include <bits/stdc++.h>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	double t;

	cin >> n >> t;
	m = (int)(t * 100 +0.5);

	while (n != 0 || m != 0) {

		vector<int> dp(m+1);

		for (int i = 0; i < n; i++) {
			int  a, b;
			double c;

			cin >> a >> c;
			
			b = (int)(c * 100 + 0.5);

			for (int j = 0; j <= m; j++) {
				if (j - b >= 0) dp[j] = max(dp[j], dp[j - b] + a);
			}
			for (int j = 1; j <= m; j++) dp[j] = max(dp[j], dp[j - 1]);
		}

		cout << dp[m] << '\n';

		cin >> n >> t;
		m = (int)(t * 100 + 0.5);
	}
}