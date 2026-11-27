#include <bits/stdc++.h>
using namespace std;

int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);
	int n;
	cin >> n;

	vector<int> A(n);
	for (auto& i : A) cin >> i;

	if (*max_element(A.begin(), A.end()) < 0) {
		cout << *max_element(A.begin(), A.end());
		return 0;
	}

	int dp[100000][2];  // 0: 제거 안 함, 1: 제거함
	dp[0][0] = A[0];
	dp[0][1] = 0;

	for (int i = 1; i < n; i++) {
		dp[i][0] = max(dp[i - 1][0] + A[i], A[i]);
		dp[i][1] = max(dp[i-1][1] + A[i], dp[i-1][0]);
	}

	int ans = A[0];
	for (int i = 0; i < n; i++) {
		ans = max({ ans, dp[i][0], dp[i][1] });
	}
	cout << ans;

}