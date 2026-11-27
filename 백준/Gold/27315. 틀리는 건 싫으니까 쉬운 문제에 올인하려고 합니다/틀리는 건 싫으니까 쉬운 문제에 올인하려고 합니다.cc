#include <bits/stdc++.h>
using namespace std;
using ll = long long;


map<int, int> idx;

void solve() {
	int n, m;
	cin >> n >> m;
	
	vector<pair<ll, ll>> A;
	vector<int> tmp;
	for (int i = 0; i < n; i++) {
		ll a, b, c, d;
		cin >> a >> b >> c >> d;

		if (d) {
			a = (a + 1) / 2;
			b /= 2;
		}

		if (c) b = 0;
		A.push_back({ a,b });
		tmp.push_back(a);
	}
	sort(A.begin(), A.end());

	priority_queue<int> pq;

	ll x, y;
	cin >> x >> y;
	
	int ix = 0;
	while (ix < n && A[ix].first <= x) {
		pq.push(-A[ix].second);
		ix++;
	}
	ll ans = 0, cnt = 0;

	while (!pq.empty() && cnt < m) {
		ll tx = -pq.top();
		pq.pop();

		ans += max(0ll, tx - y);
		cnt++;
		x++, y++;

		while (ix < n && A[ix].first <= x) {
			pq.push(-A[ix].second);
			ix++;
		}
	}

	if (cnt != m) ans = -1;
	cout << ans;

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