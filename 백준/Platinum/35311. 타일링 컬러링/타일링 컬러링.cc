#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

void solve() {
	int n, k;
	cin >> n >> k;

	if (n < k * 2 || n > 4 * k + 1) {
		cout << "NO\n";
		return;
	}

	cout << "YES\n";
	for (int i = 0; i < k * 2 - 1; i++) { cout << i + 1 << ' ' << 0 << '\n'; }
	n -= k * 2;
	for (int i = 0; i < k && n; i++, n--) { cout << i * 2 + 1 << ' ' << 1 << '\n'; }
	for (int i = 0; i < k && n; i++, n--) { cout << i * 2 + 1 << ' ' << -1 << '\n'; }
	if (n) cout << k * 2 << ' ' << 0 << '\n';
}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 1;
	cin >> t;
	for (int i = 1; i <= t; i++) { solve(); }
	return 0;
}