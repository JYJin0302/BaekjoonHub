#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

ld C[101][101];
ld nCr(int n, int r) {
	if (C[n][r] > -0.5) return C[n][r];
	if (r == 0 || n == r) return C[n][r] = 1;
	return C[n][r] = nCr(n - 1, r) + nCr(n - 1, r - 1);
}

ld pw2[101];

void solve() {
	int n;
	cin >> n;

	string s;
	cin >> s;

	vector<int> cnt(3);
	for (auto f : s) {
		if (f == 'r') cnt[0]++;
		else if (f == 'g') cnt[1]++;
		else cnt[2]++;
	}
	sort(all(cnt));

	double ans = 0;
	ans += cnt[0] * 1.5;

	C[0][0] = 1;
	C[1][0] = 1;
	C[1][1] = 1;
	for (int j = 2; j <= 100; j++) {
		C[j][0] = 1;
		for (int f = 1; f <= j; f++) { C[j][f] = C[j - 1][f] + C[j - 1][f - 1]; }
	}

	pw2[0] = 1;
	for (int i = 1; i <= 100; i++) pw2[i] = pw2[i - 1] / 2;

	for (int j = 0; j <= cnt[0]; j++) {
		ld mul = C[cnt[0]][j] * pw2[cnt[0]];
		int na = cnt[1] + j;
		int nb = cnt[2] + cnt[0] - j;
		int c = min(na, nb);
		ans += mul * 3 * c;
	}
	cout << setprecision(20);
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