#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX_N = 5000000;
bool isP[MAX_N + 10];
int dp[MAX_N + 10];

void solve() {

	int n;
	cin >> n;

	vector<int> A(n);
	for (auto& i : A) cin >> i;

	int res = MAX_N, ed = MAX_N;
	for (auto i : A) {
		int v = dp[i] / 2 + 1;
		if (ed > v) {
			ed = v;
			res = dp[i];
		}
	}

	if (res & 1) cout << "Farmer John\n";
	else cout << "Farmer Nhoj\n";
}
int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	for (int i = 2; i <= MAX_N; i++) {
		if (!isP[i]) {
			for (int j = i * 2; j <= MAX_N; j += i) isP[j] = 1;
		}
	}
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;
	for (int i = 4; i <= MAX_N; i++) {
		if (i % 2 == 0) dp[i] = i / 2;
		else {
			if (!isP[i]) dp[i] = 1;
			else dp[i] = dp[i - 4] + 2;
		}
	}
	
	int t;
	cin >> t;
	while (t--) {
		solve();
	}

}