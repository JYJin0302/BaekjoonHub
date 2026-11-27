#include <bits/stdc++.h>
using namespace std;

int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {

		int f, t, a, d, s, l, r;
		cin >> f >> t;

		vector<string> dp(10000);
		queue<int> q;
		vector<bool> check(10000);
		q.push(f);
		check[f] = 1;
		while (!q.empty()) {
			a = q.front();
			q.pop();
			if (a == t) break;
			d = (a * 2) % 10000;
			s = (a + 9999) % 10000;
			
			l = (a / 1000) + (a % 1000) * 10;
            r = (a%10) * 1000 + a/10;

			if (!check[d]) {
				check[d] = 1;
				dp[d] = dp[a] + 'D';
				q.push(d);
			}
			if (!check[s]) {
				check[s] = 1;
				dp[s] = dp[a] + 'S';
				q.push(s);
			}
			if (!check[l]) {
				check[l] = 1;
				dp[l] = dp[a] + 'L';
				q.push(l);
			}
			if (!check[r]) {
				check[r] = 1;
				dp[r] = dp[a] + 'R';
				q.push(r);
			}
		}
		cout << dp[t] << '\n';

	}
}