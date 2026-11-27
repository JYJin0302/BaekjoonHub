#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };


void solve() {

	int n;
	cin >> n;

	vector<ll> A(n);
	for (auto& i : A) cin >> i;

	sort(A.begin(), A.end());

	ll ans = 3e9;
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {

			ll curr = A[i] + A[j];

			for (int k = j+1; k < n; k++) {

				int tx = lower_bound(A.begin(), A.end(), curr - A[k]) - A.begin();
				int tx2 = tx - 1;

				while(tx2 == k || tx2 == i || tx2 == j) tx2--;
				while (tx == k || tx == i || tx == j) tx++;

				if (tx >= 0 && tx < n) ans = min(ans, abs(curr - (A[k] + A[tx])));
				if (tx2 >= 0 && tx2 < n) ans = min(ans, abs(curr - (A[k] + A[tx2])));
			}

		}
	}
	cout << ans;
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