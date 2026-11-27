#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

int gcd(int a, int b) {
	if (a > b) swap(a, b);
	if (a == 0) return b;
	return gcd(b % a, a);
}

void solve() {
	int n;
	cin >> n;

	if (n & 1) {
		cout << n / 2 << '\n';
	} else {
		int ans = n / 2 - 1;
		while (gcd(n, ans) != 1) ans--;
		cout << ans << '\n';
	}
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