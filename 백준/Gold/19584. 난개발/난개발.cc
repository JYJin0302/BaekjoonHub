#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll n, m, a, b, c;
	cin >> n >> m;

	vector<ll> y(n);
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		y[i] = b;
	}
	
	vector<pair<ll, ll>> sweep;

	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		sweep.push_back({ min(y[a - 1], y[b - 1]), -c });
		sweep.push_back({ max(y[a - 1], y[b - 1]), c });
	}

	sort(sweep.begin(), sweep.end());

	ll ans = 0;
	ll curr = 0;
	for (int i = 0; i < sweep.size(); i++) {
		curr -= sweep[i].second;
		ans = max(ans, curr);
	}
	cout << ans;
}