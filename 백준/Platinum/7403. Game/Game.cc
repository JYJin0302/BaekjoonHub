#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

void solve() {
	int n, m;
	cin >> n >> m;

	set<pair<int, int>> st;
	for (int a = 1; a <= n; a++) {
		for (int b = a + 1; b <= n; b++) { st.insert(mp(a, b)); }
	}

	vector<pair<int, int>> ans;
	for (int i = 0; i <= m; i++) {
		map<int, int> cnt;
		if (i % 2 == 0) {
			for (auto [a, b] : st) cnt[a + b]++;
			auto iter = st.begin();
			while (iter != st.end()) {
				auto [a, b] = *iter;
				if (cnt[a + b] == 1) {
					if (i == m) ans.push_back(mp(a, b));
					iter = st.erase(iter);
				} else iter++;
			}

		} else {
			for (auto [a, b] : st) cnt[a * b]++;
			auto iter = st.begin();
			while (iter != st.end()) {
				auto [a, b] = *iter;
				if (cnt[a * b] == 1) {
					if (i == m) ans.push_back(mp(a, b));
					iter = st.erase(iter);
				} else iter++;
			}
		}
	}

	cout << (int)ans.size() << '\n';
	for (auto [a, b] : ans) cout << a << ' ' << b << '\n';
}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 1;
	// cin >> t;
	while (t--) { solve(); }
	return 0;
}