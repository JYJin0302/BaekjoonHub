#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll comb[2001][2001];

ll solve(ll a, ll b) {
	if (a < 0) return 1;
	return comb[a][b];
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);


	ll n, m, k, p;
	cin >> n >> m >> k >> p;
    comb[0][0] = 1;
	comb[1][0] = 1;
	comb[1][1] = 1;
	for (int i = 2; i <= 2000; i++) {
		comb[i][0] = 1;
		for (int j = 1; j <= i; j++) {
			comb[i][j] = (comb[i - 1][j] + comb[i-1][j - 1]) % p;
		}
	}


	ll ans = 0;

	for (int i = 0; i <= k; i++) {
		ll rm = k - i;
		if (rm & 1) continue;
		rm >>= 1;

		// nHi, mHrm
		ans += solve(n + i - 1,i) * solve(m + rm - 1, rm) % p;
		ans %= p;
	}
	cout << ans;
	
}
