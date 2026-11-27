#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1e18;
vector<pair<ll, ll>> A, B;
// day, price

ll ans = 0;
void solve(int l, int r, int sl, int sr) {
	if (l > r) return;

	int m = (l + r) >> 1;

	ll ansV = -INF, ansi = sl;

	for (int i = sl; i <= sr; i++) {
		if (A[i].first >= B[m].first && B[m].second <= A[i].second) continue;

		ll tans = (B[m].second - A[i].second) * (B[m].first - A[i].first);
		if (tans > ansV) {
			ansV = tans;
			ansi = i;
		}
	}

	ans = max(ans, ansV);
	solve(l, m - 1, sl, ansi);
	solve(m + 1, r, ansi, sr);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<pair<ll, ll>> tmp;
	
	for (int i = 0; i < n; i++) {
		ll a, b;
		cin >> a >> b;

		tmp.push_back({ b, a });
	}

	sort(tmp.begin(), tmp.end());
	for (auto i : tmp) {
		ll a, b;
		tie(a, b) = i;
		if (A.empty() || b < A.back().second) {
			A.push_back({ a, b });
		}
	}
	tmp.clear();

	for (int i = 0; i < m; i++) {
		ll a, b;
		cin >> a >> b;
		tmp.push_back({ b, a });
	}
	sort(tmp.begin(), tmp.end());

	for (auto i : tmp) {
		ll a, b;
		tie(a, b) = i;
		while (!B.empty() && B.back().second <= b) {
			B.pop_back();
		}
		B.push_back({ a, b });
	}
	tmp.clear();

	/*
	for (auto i : A) cout << i.second << ' ';
	cout << '\n';
	for (auto i : B) cout << i.second << ' ';
	cout << '\n';
	*/

	n = A.size(), m = B.size();
	solve(0, m - 1, 0, n - 1);
	cout << ans;
}