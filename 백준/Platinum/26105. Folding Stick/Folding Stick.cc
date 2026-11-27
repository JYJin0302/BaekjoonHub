#include <bits/stdc++.h>
using namespace std;
using ll = long long;


vector<int> q[100010];

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> A(n+1), sA(n+1);
	for (int i = 1; i <= n; i++) {
		cin >> A[i];
		sA[i] = sA[i - 1] + A[i];
	}

	vector<int> dp(n + 1);

	priority_queue<int> pq;
	pq.push(0);
	for (int i = 1; i <= n; i++) {
		for (int j : q[i]) {
			pq.push(sA[j]);
		}

		dp[i] = sA[i] - pq.top();

		int nx = lower_bound(sA.begin(), sA.end(), dp[i] + sA[i]) - sA.begin();
		q[nx].push_back(i);
	}

	int ans = dp[n];

	for (int i = 1; i <= n; i++) {
		if (sA[n] - sA[i] <= dp[i]) ans = min(ans, dp[i]);
	}
	cout << ans;
}