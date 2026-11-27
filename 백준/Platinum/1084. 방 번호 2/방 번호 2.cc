#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

void solve() {
	int n;
	cin >> n;

	vector<ll> cost(n);
	for (int i = 0; i < n; i++) cin >> cost[i];

	ll M;
	cin >> M;

	if (*min_element(all(cost)) > M) {
		cout << 0 << '\n';
		return;
	}

	if (n == 1) {
		cout << 1 << '\n';
		cout << 0 << '\n' << 0 << '\n';
		return;
	}

	vector<ll> preM(n);
	for (int i = 0; i < n; i++) {
		preM[i] = cost[i];
		if (i) preM[i] = min(preM[i - 1], cost[i]);
	}

	ll min0 = *min_element(all(cost));
	ll min1 = *min_element(1 + all(cost));

	if (min1 > M) {
		cout << 1 << '\n';
		cout << 0 << '\n' << 0 << '\n';
		return;
	}

	ll maxLen = 1 + (M - min1) / min0;

	ll curLen = maxLen;
	vector<ll> used(n);
	for (int i = n - 1; i >= 0; i--) {
		if (i == 0) {
			used[0] = M / cost[0];
			break;
		}
		ll L = 1, R = curLen;
		while (L <= R) {
			ll md = (L + R) >> 1;
			if ((md && M / md >= cost[i]) && curLen == md + (M - cost[i] * md) / preM[i]) {
				L = md + 1;
			} else R = md - 1;
		}

		used[i] = L - 1;
		M -= used[i] * cost[i];
		curLen -= used[i];
	}

	string ans1, ans2;
	for (int i = n - 1; i >= 0; i--) {
		int len = min(used[i], (ll)50 - (int)ans1.size());
		while (len--) { ans1 += char('0' + i); }
	}
	for (int i = 0; i <= n - 1; i++) {
		int len = min(used[i], (ll)50 - (int)ans2.size());
		while (len--) { ans2 += char('0' + i); }
	}
	reverse(all(ans2));
	cout << maxLen << '\n' << ans1 << '\n' << ans2 << '\n';
}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 1;
	// cin >> t;
	for (int i = 1; i <= t; i++) { solve(); }
	return 0;
}