#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

int W[101];
int V[101];
int dp[101010];
int pre[101010];
int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> W[i] >> V[i];
	for (int i = 1; i <= n; i++) {
		swap(pre, dp);
		for (int j = 1; j <= k; j++) {
			dp[j] = pre[j];
			if (j >= W[i]) dp[j] = max(dp[j], pre[j - W[i]] + V[i]);
		}
	}
	cout << dp[k];
}