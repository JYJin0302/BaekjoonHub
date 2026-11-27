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

	if (n == 1) {
		cout << 1 << '\n';
	} else if (k == 2) {
		for (int i = 2; i <= n; i++) cout << i << ' ';
		cout << 1 << '\n';
	} else cout << -1 << '\n';
}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 1;
	cin >> t;
	for (int i = 1; i <= t; i++) { solve(); }
	return 0;
}