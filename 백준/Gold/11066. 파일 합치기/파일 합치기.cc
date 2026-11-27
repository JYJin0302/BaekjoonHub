#include <bits/stdc++.h>
using namespace std;

// dp[i][j] -> i부터 j까지 붙이는데 드는 최소비용
vector<vector<int>> dp;
vector<int> A;
vector<int> ssum;

int merge(int x, int y) {

	if (y == x) return dp[x][y] = 0;
	if (y == x + 1) return dp[x][y] = A[x] + A[y];

	if (dp[x][y] != 0) return dp[x][y];

	int temp = 1000000000;
	for (int i = x; i <= y-1; i++) {
		temp = min(temp, merge(x, i) + merge(i + 1, y));
	}

	return dp[x][y] = temp + ssum[y] - ssum[x] + A[x];
}




int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {

		int n;
		int ans = 0;
		cin >> n;
		A = vector<int>(n);
		for (auto& i : A) cin >> i;

		ssum = vector<int>(n);
		ssum[0] = A[0];
		for (int i = 1; i < n; i++) {
			ssum[i] = ssum[i - 1] + A[i];
		}

		dp = vector<vector<int>> (n, vector<int>(n));

		cout << merge(0, n - 1) << '\n';
	}
}