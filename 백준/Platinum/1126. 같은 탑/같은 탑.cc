#include <bits/stdc++.h>
using namespace std;

vector<int> dp, dp2;
// dp[x] : 두 탑의 높이차가 x일때 높은 탑의 높이

int main() {

	int n;
	cin >> n;

	dp = vector<int>(500001, -1);
	dp[0] = 0;
	
	int ans = -1;
	vector<int> A(n);
	for (auto& i : A) cin >> i;

	for (int i : A) {
		dp2 = vector<int>(500001, -1);
		for (int j = 0; j <= 500000; j++) {
			if (dp[j] == -1) continue;
			if (i + j <= 500000) dp2[i+j] = max(dp2[i+j], dp[j]+i);

			int tj = dp[j] - j + i;
			dp2[abs(tj - dp[j])] = max(dp2[abs(tj - dp[j])], max(tj, dp[j]));
		}
		for (int j = 0; j <= 500000; j++) {
			dp[j] = max(dp[j], dp2[j]);
		}

	}
	if (dp[0] == 0) dp[0] = -1;
	cout << dp[0];

}