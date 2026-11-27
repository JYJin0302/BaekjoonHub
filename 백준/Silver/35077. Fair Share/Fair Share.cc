#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

void solve() {
	int n;
	cin >> n;

	vector<pair<int, int>> A(n);
	int totB = 0;
	int totA = 0;
	for (auto& [a, b] : A) {
		cin >> a >> b;
		totB += b;
		totA += a;
	}

	for (int i = 0; i < n; i++) {
		if (totB - (totA - A[i].x) <= A[i].y) {
			cout << i + 1 << '\n';
			return;
		}
	}
	cout << "impossible\n";
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