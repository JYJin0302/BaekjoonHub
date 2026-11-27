#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {

	ll n;
	cin >> n;
	vector<ll>A(n);
	for (auto& i : A) cin >> i;

	vector<vector<ll>> dp(n - 1, vector<ll>(21));
	dp[0][A[0]] = 1;

	for (int i = 1; i < n - 1; i++) {

		for (int k = 0; k <= 20; k++) {
			if (k + A[i] <= 20) dp[i][k + A[i]] += dp[i - 1][k];
			if (k - A[i] >= 0) dp[i][k - A[i]] += dp[i - 1][k];
		}
	}

	cout << dp[n - 2][A[n - 1]];
}