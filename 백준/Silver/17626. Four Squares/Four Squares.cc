#include <bits/stdc++.h>
using namespace std;
#define INF 100000

int main() {
	int n;
	cin >> n;

	vector<int> dp(50001, INF);
	dp[0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j * j <= i; j++) {
			dp[i] = min(dp[i], dp[i - j * j] + 1);
		}
	}

	cout << dp[n];
}