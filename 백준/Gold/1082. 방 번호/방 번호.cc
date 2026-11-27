#include <bits/stdc++.h>
using namespace std;

string convert(string a) {
	int idx = 0;
	while (a[idx] == '0' && idx < a.size()) idx++;

	if (idx == a.size()) return "0";
	a = a.substr(idx, a.size());
	return a;
}

string cmp(string a, string b) {

	if (a.size() > b.size()) return a;
	if (a.size() < b.size()) return b;

	for (int i = 0; i < a.size(); i++) {
		if (a[i] > b[i]) return a;
		if (a[i] < b[i]) return b;
	}

	return a;
}

int main() {

	int n, m;
	cin >> n;

	vector<int> cost(n);
	for (auto& i : cost) cin >> i;
	cin >> m;

	vector<string> dp(m+1);
	for (int i = 0; i <= m; i++) {

		if (i > 0) dp[i] = dp[i - 1];

		for (int j = 0; j < n; j++) {
			if (cost[j] <= i) {
				dp[i] = cmp(dp[i], dp[i - cost[j]] + char('0' + j));
			}
		}
		dp[i] = convert(dp[i]);
	}

	cout << dp[m];
}