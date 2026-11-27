#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, a, b, c, d;
	cin >> n;

	vector<pair<int, int>> A;

	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		A.push_back({ min(a, b), max(a, b) });
	}

	sort(A.begin(), A.end());

	vector<int> dp(n);
	dp[0] = 1;
	for (int i = 1; i < n; i++) {
		tie(a, b) = A[i];
		for (int j = 0; j < i; j++) {
			tie(c, d) = A[j];
			if (d <= b && c <= a) dp[i] = max(dp[i], dp[j]);
		}
		dp[i]++;
	}

	cout << *max_element(dp.begin(), dp.end());

}