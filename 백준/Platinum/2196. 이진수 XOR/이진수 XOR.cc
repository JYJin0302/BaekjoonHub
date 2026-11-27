#include <bits/stdc++.h>
using namespace std;

int b, e;
int conv(string s) {

	int res = 0;
	for (auto i : s) {
		res = res * 2 + (i - '0');
	}
	return res;
}

string conv2(int n) {
	string res;

	for (int i = b-1; i >= 0;i --) {
		res += char('0' + n / (1 << i));
		n %= (1 << i);
	}

	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> b >> e;
	const int INF = 1 << 18;

	string s;
	cin >> s;

	int t = conv(s);

	vector<int> dp(1 << 16, INF);
	vector<int> A(e);

	for (int i = 0; i < e; i++) {
		cin >> s;

		int val = conv(s);
		A[i] = val;
		dp[val] = 0;
	}

	queue<int> q;
	for (auto i : A) q.push(i);
	while (!q.empty()) {

		int a = q.front();
		q.pop();

		for (auto i : A) {
			int ta = a ^ i;
			if (dp[ta] == INF) {
				dp[ta] = dp[a] + 1;
				q.push(ta);
			}
		}
	}

	for (auto i : A) dp[i] = 2;
	for (auto i : A) {
		for (auto j : A) {
			dp[i ^ j] = min(dp[i ^ j], 1);
		}
	}


	if (dp[t] != INF) {
		cout << dp[t] << '\n' << conv2(t);
		return 0;
	}

	int ans = -1, ans_cnt = 17, ans_dp = INF;
	for (int i = 0; i < (1 << b); i++) {

		if (dp[i] == INF) continue;
		
		int cnt = 0;
		for (int k = 0; k < b; k++) {
			int v1 = t & (1 << k);
			int v2 = i & (1 << k);
			if (v1 != v2) cnt++;
		}

		if (ans_cnt > cnt) {
			ans_cnt = cnt;
			ans = i;
			ans_dp = dp[i];
		}
		else if (ans_cnt == cnt) {
			if (ans_dp > dp[i]) {
				ans_dp = dp[i];
				ans = i;
			}
		}
	}

	cout << dp[ans] << '\n' << conv2(ans);

}