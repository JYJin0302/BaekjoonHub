#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, mod = 1e9+7;
	cin >> n;
	vector<int>A(n);

	for (auto& i : A)cin >> i;
	sort(A.begin(), A.end());


	vector<ll> twos(n);
	twos[0] = 1;
	for (int i = 1; i < n; i++) {
		twos[i] = twos[i - 1] * 2;
		twos[i] %= mod;
	}

	ll ans = 0;
	for (int i = 0; i < n; i++) {
		ans += (-twos[n - 1 - i] + twos[i])* A[i];
		ans %= mod;
	}

	cout << ans;
}