#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {

	int n, l, r;
	cin >> n >> l >> r;

	ll dp[101][101][101];
	dp[1][1][1] = 1;
    
    
	for (int i = 2; i <= n; i++) {
        
		for (int j = 1; j <= l; j++) {
			for (int k = 1; k <= r; k++) {

				dp[i][j][k] = dp[i - 1][j][k-1] + dp[i-1][j-1][k] + dp[i-1][j][k] *(i-2);
				dp[i][j][k] %= 1000000007;
			}
		}
	}

	cout << dp[n][l][r];
}