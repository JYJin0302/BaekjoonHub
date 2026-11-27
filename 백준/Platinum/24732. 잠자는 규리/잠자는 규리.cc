#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair

const ll mod = 1e9 + 7;

vector<long long> calc(const vector<long long>& v, int N) {
	vector<long long> ans(N);
	ans[0] = 1;
	ll res = v[0];
	vector<pair<ll, ll>> st;
	st.push_back(mp(v[0], 1));
	for (int x = 1; x < N; x++) {
		int val = v[x];
		ll tot = 0;
		while (!st.empty()) {
			auto [a, b] = st.back();
			if (a < val) break;
			st.pop_back();
			tot += b;
			tot %= mod;
			res -= a * b % mod;
			res = (res + mod) % mod;
		}

		res += tot * val % mod;
		res %= mod;
		st.push_back(mp(val, (res + tot) % mod));
		ans[x] = res;
		res += val * res;
	}
	return ans;
}
