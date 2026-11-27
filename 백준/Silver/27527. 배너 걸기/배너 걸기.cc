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

	int n, m;
	cin >> n >> m;

	vector<int> A(n);
	for (auto& i : A) cin >> i;

	int tar = (m * 9 + 9) / 10;

	map<int, int> cnt;

	bool ok = 0;
	int l = 0, r = m;
	for (int i = l; i < r; i ++) {
		cnt[A[i]]++;
		if (cnt[A[i]] >= tar) ok = 1;
	}

	while (r < n) {
		cnt[A[l]]--;
		l++;
		cnt[A[r]]++;
		if (cnt[A[r]] >= tar) ok = 1;
		r++;
	}

	if (ok) cout << "YES";
	else cout << "NO";
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}

}