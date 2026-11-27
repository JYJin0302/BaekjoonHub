#include <bits/stdc++.h>
using namespace std;

// 0 과 n-1 이 연결되지 않은 경우 -> case 1
// 두 개의 0중 하나가 n-1과 연결된 경우 -> case 2, 3
// 두 개의 0 모두 n-1과 연결된 경우 -> case 4

int main() {

	int t, n, w;
	cin >> t;
	while (t--) {
		cin >> n >> w;
		vector<int> A(n), B(n);
		for (auto& i : A) cin >> i;
		for (auto& i : B) cin >> i;

		int ans = 2 * n;
		if (n == 1) {
			if (A[0] + B[0] <= w) cout << 1 << '\n';
			else cout << 2 << '\n';
			continue;
		}

		// case 1
		vector<vector<int>> dp(n, vector<int>(3));  // 0: 위 처리, 1 : 아래 처리, 2: 모두 처리

		// initialize
		dp[0][0] = 1;
		dp[0][1] = 1;
		if (A[0] + B[0] <= w) dp[0][2] = 1;
		else dp[0][2] = 2;

		// dp
		for (int i = 1; i < n; i++) {
			dp[i][0] = dp[i - 1][2] + 1;
			if (A[i - 1] + A[i] <= w) dp[i][0] = min(dp[i][0], dp[i - 1][1] + 1);

			dp[i][1] = dp[i - 1][2] + 1;
			if (B[i - 1] + B[i] <= w) dp[i][1] = min(dp[i][1], dp[i - 1][0] + 1);

			dp[i][2] = min(dp[i][0], dp[i][1]) + 1;
			if (A[i] + B[i] <= w) dp[i][2] = min(dp[i][2], dp[i - 1][2] + 1);

			if (i >= 1 && A[i - 1] + A[i] <= w && B[i - 1] + B[i] <= w) {
				if (i == 1) dp[i][2] = min(dp[i][2], 2);
				else dp[i][2] = min(dp[i][2], dp[i - 2][2] + 2);
			}
		}

		ans = min(ans, dp[n - 1][2]);

		// case 2
		if (A[0] + A[n - 1] <= w) {
			dp = vector<vector<int>>(n, vector<int>(3));  // 0: 위 처리, 1 : 아래 처리, 2: 모두 처리

			// initialize
			dp[0][0] = 1;
			dp[0][1] = 1;
			dp[0][2] = 2;

			// dp
			for (int i = 1; i < n; i++) {
				dp[i][0] = dp[i - 1][2] + 1;
				if (A[i - 1] + A[i] <= w) dp[i][0] = min(dp[i][0], dp[i - 1][1] + 1);
				dp[1][0] = 3;

				dp[i][1] = dp[i - 1][2] + 1;
				if (B[i - 1] + B[i] <= w) dp[i][1] = min(dp[i][1], dp[i - 1][0] + 1);

				dp[i][2] = min(dp[i][0], dp[i][1]) + 1;
				if (A[i] + B[i] <= w) dp[i][2] = min(dp[i][2], dp[i - 1][2] + 1);

				if (i >= 2 && A[i - 1] + A[i] <= w && B[i - 1] + B[i] <= w) {
					dp[i][2] = min(dp[i][2], dp[i - 2][2] + 2);
				}
			}
			ans = min(ans, dp[n - 1][1]);

		}

		// case 3
		if (B[0] + B[n - 1] <= w) {
			dp = vector<vector<int>>(n, vector<int>(3));  // 0: 위 처리, 1 : 아래 처리, 2: 모두 처리

			// initialize
			dp[0][0] = 1;
			dp[0][1] = 1;
			dp[0][2] = 2;

			// dp
			for (int i = 1; i < n; i++) {
				dp[i][0] = dp[i - 1][2] + 1;
				if (A[i - 1] + A[i] <= w) dp[i][0] = min(dp[i][0], dp[i - 1][1] + 1);
				
				dp[i][1] = dp[i - 1][2] + 1;
				if (B[i - 1] + B[i] <= w) dp[i][1] = min(dp[i][1], dp[i - 1][0] + 1);
				dp[1][1] = 3;

				dp[i][2] = min(dp[i][0], dp[i][1]) + 1;
				if (A[i] + B[i] <= w) dp[i][2] = min(dp[i][2], dp[i - 1][2] + 1);

				if (i >= 2  && A[i - 1] + A[i] <= w && B[i - 1] + B[i] <= w) {
					dp[i][2] = min(dp[i][2], dp[i - 2][2] + 2);
				}
			}
			ans = min(ans, dp[n - 1][0]);

		}
		// case 4
		if (A[0] + A[n - 1] <= w && B[0] + B[n - 1] <= w) {
			if (n == 2) ans = 2;
			else {
				dp = vector<vector<int>>(n, vector<int>(3));  // 0: 위 처리, 1 : 아래 처리, 2: 모두 처리

				// initialize
				dp[0][0] = 1;
				dp[0][1] = 1;
				dp[0][2] = 2;

				dp[1][0] = 3;
				dp[1][1] = 3;
				if (A[1] + B[1] <= w) dp[1][2] = 3;
				else dp[1][2] = 4;
				// dp
				for (int i = 2; i < n - 1; i++) {
					dp[i][0] = dp[i - 1][2] + 1;
					if (A[i - 1] + A[i] <= w) dp[i][0] = min(dp[i][0], dp[i - 1][1] + 1);

					dp[i][1] = dp[i - 1][2] + 1;
					if (B[i - 1] + B[i] <= w) dp[i][1] = min(dp[i][1], dp[i - 1][0] + 1);

					dp[i][2] = min(dp[i][0], dp[i][1]) + 1;
					if (A[i] + B[i] <= w) dp[i][2] = min(dp[i][2], dp[i - 1][2] + 1);

					if (A[i - 1] + A[i] <= w && B[i - 1] + B[i] <= w) {
						if (i == 2) dp[i][2] = min(dp[i][2], 4);
						else dp[i][2] = min(dp[i][2], dp[i - 2][2] + 2);
					}
				}
				ans = min(ans, dp[n - 2][2]);

			}
		}
		cout << ans << '\n';
	}
}