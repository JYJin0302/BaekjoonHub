#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

void solve() {
	vector<int> M = {1, 2, 5, 10, 20, 50, 100, 200, 500};
	int n;
	cin >> n;

	vector<int> ans;
	for (int i = 0; i < 9; i++) {
		int val = M[i];
		int c = n / val;
		if (c & 1) {
			for (int j = i; j >= 0; j--) {
				while (n >= M[j]) {
					n -= M[j];
					ans.push_back(M[j]);
				}
			}

			cout << (int)ans.size() << '\n';
			for (auto f : ans) cout << f << ' ';
			cout << '\n';
			return;
		}
	}
	if ((n % 2000) / 100 == 12) {
		ans.push_back(200);
		ans.push_back(500);
		ans.push_back(500);
		n -= 1200;
		for (int j = 8; j >= 0; j--) {
			while (n >= M[j]) {
				n -= M[j];
				ans.push_back(M[j]);
			}
		}
		cout << (int)ans.size() << '\n';
		for (auto f : ans) cout << f << ' ';
		cout << '\n';
		return;
	}

	cout << "splittable\n";
	// cout << n << '\n';
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