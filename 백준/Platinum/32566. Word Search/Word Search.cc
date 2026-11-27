#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

const ll p1 = 1000003;
const ll p3 = 9992663;
const int p2 = 998244353;

char G[2020][2020];

int ans[2020][2020];

void solve() {
	int n1, m1;
	cin >> n1 >> m1;

	vector<int> H(n1);

	for (int i = 0; i < n1; i++) {
		string s;
		cin >> s;
		ll val = 0;
		for (int j = 0; j < m1; j++) {
			val = val * p1 + s[j] - 'a' + 1;
			val %= p2;
		}
		H[i] = val;
	}

	ll hVal = 0;
	for (auto f : H) {
		hVal = hVal * p3 + f;
		hVal %= p2;
	}
	// cout << "hval: " << hVal << '\n';

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) { cin >> G[i][j]; }
	}

	vector<ll> val(n);
	ll mul = 1;
	for (int i = 0; i < m1; i++) mul = mul * p1 % p2;

	ll mul2 = 1;
	for (int i = 0; i < n1; i++) mul2 = mul2 * p3 % p2;

	for (int j = 0; j < m; j++) {
		for (int i = 0; i < n; i++) {
			val[i] = val[i] * p1 + G[i][j] - 'a' + 1;
			val[i] %= p2;

			if (j >= m1) {
				val[i] = val[i] + p2 - mul * (G[i][j - m1] - 'a' + 1) % p2;
				val[i] %= p2;
			}
		}

		ll cur = 0;
		for (int i = 0; i < n; i++) {
			cur = cur * p3 + val[i];
			if (i >= n1) cur = cur + p2 - mul2 * val[i - n1] % p2;
			cur %= p2;

			// cout << "i , j " << i << ' ' << j << " => " << cur << '\n';

			if (cur == hVal) {
				// cout << "found: " << i << ' '<< j << '\n';
				ans[i - n1 + 1][j - m1 + 1]++;
				ans[i - n1 + 1][j + 1]--;
				ans[i + 1][j - m1 + 1]--;
				ans[i + 1][j + 1]++;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i) ans[i][j] += ans[i - 1][j];
			if (j) ans[i][j] += ans[i][j - 1];
			if (i && j) ans[i][j] -= ans[i - 1][j - 1];

			if (ans[i][j]) cout << G[i][j];
			else cout << '.';
		}
		cout << '\n';
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