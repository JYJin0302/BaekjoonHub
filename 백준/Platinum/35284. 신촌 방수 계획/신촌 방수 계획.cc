#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

int root[101010];
int find(int n) {
	if (root[n] == n) return n;
	return root[n] = find(root[n]);
}

bool on[101010];

void solve() {
	int n, m;
	cin >> n >> m;

	vector<ll> C(n + 1);
	for (int i = 1; i <= n; i++) cin >> C[i];

	for (int i = 1; i <= n; i++) root[i] = i;

	vector<array<ll, 3>> edg;
	while (m--) {
		ll a, b, c;
		cin >> a >> b >> c;
		edg.push_back({c, a, b});
	}

	for (int i = 1; i <= n; i++) edg.push_back({C[i], i, i});
	sort(all(edg));

	ll ans = 0;

	for (auto f : edg) {
		auto [c, a, b] = f;
		if (a == b) {
			int ta = find(a);
			if (on[ta]) {
			} else {
				on[ta] = 1;
				ans += c;
			}
		} else {
			int ta = find(a);
			int tb = find(b);
			if (ta == tb || (on[ta] && on[tb])) {
			} else {
				root[tb] = ta;
				on[ta] |= on[tb];
				ans += c;
			}
		}
	}

	ll res = ans;

	for (int i = 1; i <= n; i++) root[i] = i;
	ans = 0;
	for (auto f : edg) {
		auto [c, a, b] = f;
		if (a == b) {
			continue;
		} else {
			int ta = find(a);
			int tb = find(b);
			if (ta == tb) {
			} else {
				root[tb] = ta;
				ans += c;
			}
		}
	}

	res = min(res, ans);
	cout << res << '\n';
}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 1;
	//cin >> t;
	while (t--) { solve(); }
	return 0;
}