#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

ll n, e;

ll res[606060];
void setup() {
	memset(res, -1, sizeof res);
	map<ll, ll> tmp;
	tmp[0] = 0;
	ll cur = 0;
	for (int i = 1; i <= n * 3; i++) {
		cur = (cur + i) % n;
		int ix = i % n;
		if (tmp.find(cur) != tmp.end()) {
			ll z = tmp[cur];
			if (res[ix] == -1 || res[ix] > i - z - 1) { res[ix] = i - z - 1; }
		}
		tmp[cur] = i;
	}
}

void solve() {
	cin >> n >> e;

	if (n == 1){
		cout << "infinity\n";
		return;
	}
	setup();
	// for(int i =0;  i< n * 2; i++) cout << res[i] << ' ';
	// cout << '\n';

	vector<bool> vis(n);
	ll ans = 0;

	map<ll, bool> chk;
	map<ll, array<ll, 3>> record;
	ll step = 0;
	while (e) {
		ll r = e % n;

		//cout << ans << ' ' << e << ' ' << step << endl;
		if (chk[e]) {
			cout << "infinity\n";
			return;
		}
		chk[e] = 1;
		if (record.find(e % (2*n)) != record.end()){
			auto f = record[e % (2*n)];
			ll sDif = (step - f[2]) * (f[0] - e);
			ll D = ans - f[1];
			ll cc = e / (f[0] - e);
			

			ans += D* cc - sDif * cc * (cc+1)/2;
			e %= f[0] - e;

			//cout << "process: " << ans << ' '<< e << endl;
		}

		record[e % (2*n)] = {e, ans, step};

		ll k = res[r];

		if (k > e) {
			ans += e * (e + 1) / 2;
			step += e;
			e = 0;
		} else {
			ans += e * (k + 1) - k * (k + 1) / 2;
			step += k + 1;
			e -= k;
			e++;
		}
	}
	cout << ans << '\n';
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