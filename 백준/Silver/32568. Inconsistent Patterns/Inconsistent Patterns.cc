#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

void solve() {
	int n, m;
	cin >> n >> m;

	vector<array<int, 4>> A(n);
	for (int i = 0; i < n; i++) {
		if (i == n - 1) {
			A[i][1] = m - 2 * (n - 1);
			A[i][0] = A[i][1] - 1;
			A[i][2] = A[i][3] = 1;
		} else {
			A[i][0] = 1;
			A[i][1] = 2;
			A[i][3] = (m - 1) / (n - 1) + (i < (m - 1) % (n - 1));
			A[i][2] = A[i][3] / 2 + 1;
		}
	}

	for (int i = 0; i < n; i++) { cout << A[i][2] << ' ' << A[i][3] << ' ' << A[i][0] << ' ' << A[i][1] << '\n'; }
}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 1;
	// cin >> t;
	while (t--) { solve(); }
	return 0;
}