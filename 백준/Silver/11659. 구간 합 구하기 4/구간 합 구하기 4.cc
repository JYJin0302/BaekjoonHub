#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m, a, b;
	cin >> n >> m;
	vector<int> A(n+1);
	for (int i = 1; i <= n; i++) cin >> A[i];

	vector<int> dp(n+1);
	for (int i = 1; i <= n; i++) dp[i] = dp[i - 1] + A[i];

	while (m--) {
		cin >> a >> b;
		cout << dp[b] - dp[a - 1] << '\n';
	}
}