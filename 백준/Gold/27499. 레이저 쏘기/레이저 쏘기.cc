#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int gcd(int a, int b) {
	if (a > b) swap(a, b);
	if (a == 0) return b;
	return gcd(b % a, a);
}

map<pair<int, int>, int> cnt;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m, k;
	cin >> n >> m >> k;

	vector<pair<int, int>> A(n);
	for (auto& i : A) cin >> i.first >> i.second;

	int ans = 0;
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < n; j++) {
			int a, b;
			tie(a, b) = A[j];

			if (i & 1) a = m * (i + 1) - a;
			else a = m * i + a;

			int gc = gcd(a, b);
			a /= gc, b /= gc;
			cnt[{a, b}]++;
			ans = max(ans, cnt[{a, b}]);
		}
	}
	cout << ans;
}