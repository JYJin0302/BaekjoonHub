#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

void solve() {
	int n, k, q;
	cin >> n >> k >> q;

	vector<pair<int, int>> Q(q + 1);
	vector<pair<int, int>> A;
	for (int i = 1; i <= q; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		Q[i] = mp(b, c);

		A.push_back(mp(b, i));
		A.push_back(mp(c, -i));
	}

	sort(all(A));
	int cnt = 0;
	vector<int> ans(q + 1);
	for (auto [a, b] : A) {
		if (b > 0) {
			cnt++;
		} else {
			b *= -1;
			if (cnt == n) ans[b] = 1;
			cnt--;
		}
	}

	// valid check;

	A.clear();
	for (int i = 1; i <= q; i++) {
		auto [a, b] = Q[i];
		if (ans[i]) {
			A.push_back(mp(a, 1));
			A.push_back(mp(b, -1));
		}
	}

	cnt = 0;
	sort(all(A));
	for(auto[a,b]:A){
		cnt += b;
		if (cnt > k){
			cout << "impossible\n";
			return;
		}
	}

	for(int i = 1; i <= q; i++) cout << ans[i];
	cout << '\n';
}


int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 1;
	// cin >> t;
	for (int i = 1; i <= t; i++) {
		// cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}