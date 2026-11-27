#include <bits/stdc++.h>
using namespace std;

int dp[101][10001];  // 비활성화 개수, 비용 => 최대 비활성화 메모리

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, a;
	cin >> n >> m;

	vector<int> Memory(n);
	for (auto& i : Memory) cin >> i;

	int totalcost = 0;
	vector<int> cost(n);
	for (int i = 0; i < n; i++) {
		cin >> a;
		cost[i] = a;
		totalcost += a;
	}

	for (int i = 0; i < n; i++) {

		for (int k = 0; k <= totalcost; k++) {
			if (i == 0) {
				if (k >= cost[i]) dp[i][k] = Memory[i];
			}
			else if (k < cost[i]) dp[i][k] = dp[i - 1][k];
			else dp[i][k] = max(dp[i-1][k - cost[i]] + Memory[i], dp[i - 1][k]);
		}
	}

	for (int k = 0; k <= totalcost; k++) {
		if (dp[n - 1][k] >= m) {
			cout << k;
			break;
		}
	}
}