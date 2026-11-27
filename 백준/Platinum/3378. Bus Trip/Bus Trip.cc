#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

ll dp[50505];

void solve() {
	int n, m, p, t;
	cin >> n >> m >> p >> t;

	memset(dp, -1, sizeof dp);
	dp[1] = 0;

	vector<array<int, 5>> B;
	while (m--) {
		int u, v;
		int a, b, c, d;
		cin >> u >> v >> a >> b >> c >> d;
		B.push_back({a, d, c - b, u, v});
	}
	sort(all(B));
	set<array<ll, 3>> U; // Time, index, val

	int ix = 0;
	while(1){
		ll nxtT1 = t + 10, nxtT2 = t + 10;
		if (ix < (int)B.size()) nxtT1 = B[ix][0];
		if (!U.empty()) nxtT2 = (*U.begin())[0];

		if (min(nxtT1, nxtT2) > t) break;
		if (nxtT2 <= nxtT1){
			// update
			auto f = *U.begin();
			U.erase(U.begin());
			int v = f[1];
			ll val = f[2];
			dp[v] = max(dp[v], val);
		}
		else{
			// process
			int u = B[ix][3], v = B[ix][4];
			ll tmpT = B[ix][1];
			ll val = B[ix][2];
			if (dp[u] != -1){
				U.insert({tmpT, v, dp[u] + val});
			}
			ix++;
		}
	}

	if (dp[p] == -1) cout << -1 << '\n';
	else cout << t - dp[p] << '\n';
}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 1;
	// cin >> t;
	while (t--) { solve(); }
	return 0;
}