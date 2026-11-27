#include <bits/stdc++.h>
using namespace std;
using ll = long long;



void solve() {

	int t, s, n;
	cin >> t >> s >> n;

	vector<tuple<int, int, int>> A;
	vector<int> B(101, 10111);

	for (int i = 0; i < s; i++) {

		int a, b, c;
		cin >> a >> b >> c;

		if (a + b > t) continue;

		A.push_back({ a+b, a, c });
	}
	A.push_back({ 0, 0, 1 });

	sort(A.begin(), A.end());

	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;

		B[a] = min(B[a], b);
	}

	for (int i = 1; i <= 100; i++) B[i] = min(B[i], B[i - 1]);

	vector<int> dp(10001);
	// dp[x] : x 초 지났을 때 최대 스키 횟수

	for (auto i : A) {

		int a, b, c;
		tie(a, b, c) = i;

		int tval = 0;
		for (int j = a; j <= t; j++) {
			dp[j] = max(dp[j], dp[b] + (j - a) / B[c]);
		}
	}

	cout << dp[t];
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}

}