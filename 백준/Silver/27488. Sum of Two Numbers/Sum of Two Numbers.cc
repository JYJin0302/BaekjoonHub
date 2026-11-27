#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

ll gcd(ll a, ll b) {
	if (a > b) swap(a, b);
	if (a == 0) return b;
	return gcd(b % a, a);
}

ll fastPow(ll b, ll ex, ll m) {
	ll res = 1;
	while (ex) {
		if (ex & 1) res = res * b % m;
		b = b * b % m;
		ex >>= 1;
	}
	return res;
}


void solve() {

	int n;
	cin >> n;
    
	int ans1 = 0, ans2 = 0;
	int b = 1;
	while (n > 0) {
		int tn = n % 10;
		if (tn % 2 == 0) {
			ans1 += tn / 2 * b;
			ans2 += tn / 2 * b;
		}
		else {
			ans1 += tn / 2 * b;
			ans2 += (tn / 2 + 1) * b;
			swap(ans1, ans2);
		}
		b *= 10;
		n /= 10;
	}
	cout << ans1 << ' ' << ans2 << '\n';
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}