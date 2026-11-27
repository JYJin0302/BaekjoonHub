#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll dp[3000][3000];  // dp[i][j]: i번째 수와 j번째 수가 나란히 포함된 수열의 j까지의 합
bool check[3000][3000];  // 3개 이상
int ind[1000001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll n, a, b;
	cin >> n;
	vector<ll> A(n);
	
    
	for (int i = 0; i < n; i++) {
		cin >> A[i]; ind[A[i]] = i + 1;
	}

	for (int i = 0; i < n; i++) {
		a = A[i];
		for (int j = i + 1; j < n; j++) {
			b = A[j];

			
			if (2*a-b >= 0 && ind[2*a-b] - 1 >= 0) {
                int t = ind[2*a-b] - 1;
				check[i][j] = 1;
				dp[i][j] = dp[t][i] + b;
			}
			else dp[i][j] = a + b;
		}
	}
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (check[i][j] && ans < dp[i][j]) ans = dp[i][j];
		}
	}
	cout << ans;
}