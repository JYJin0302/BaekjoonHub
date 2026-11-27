#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

void solve() {
	ll b, x;
	cin >> b >> x;

	set<ll> st;
	for (int i = 1; i < b; i++) st.insert(i);

	int cnt = x;
	while (cnt--) {
		ll val = *st.begin();
		cout << val << '\n';
		st.erase(st.begin());

		for (int len = 2; len < 60; len++) {
			ll T = val * len;
			ll tmp = T;

			int tLen = 0;
			while (T) {
				tLen++;
				T /= b;
			}
			if (tLen == len) st.insert(tmp);
		}
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 1;
	// cin >> t;
	while (t--) { solve(); }
	return 0;
}