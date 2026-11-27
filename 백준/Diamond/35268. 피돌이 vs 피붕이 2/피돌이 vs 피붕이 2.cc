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

	vector<int> A(n);
	for (auto& i : A) cin >> i;

	if (n & 1) {
		cout << (n + 1) / 2 << '\n';
	} else {
		int cnt = 1;
		int val = 0;
		for (int i = 0; i < n; i++) {
			if (A[i] > n / 2) val++;
			else val--;

			if (val == 0) cnt ^= 1;
		}

		cout << n / 2 + cnt << '\n';
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 1;
	// cin >> t;
	for (int i = 1; i <= t; i++) { solve(); }
	return 0;
}