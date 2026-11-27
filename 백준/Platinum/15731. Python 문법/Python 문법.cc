#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {

	string s;
	cin >> s;

	ll n = s.size(), mod = 1e9+7;

	vector<ll> A(n+1);
	A[0] = 1;

	for (int i = 0; i < n - 1; i++) {
		if (s[i] == 'f') {
			for (int j = n - 1; j >= 0; j--) {
				A[j+1] = A[j];
			}
			A[0] = 0;
		}
		else {
			for (int j = n - 1; j >= 0; j--) {
				A[j] += A[j + 1];
				A[j] %= mod;
			}
		}
	}

	ll ans = 0;
	for (int i = 0; i <= n; i++) {
		ans += A[i];
		ans %= mod;
	}

	cout << ans;

}