#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mod = 998244353;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	ll ans = 0;
	vector<bool> A(n + 1);

	for (int i = 2; i <= n; i++) {
		if (!A[i]) {
			A[i] = 1;
			ans += i;
			for (int j = i * 2; j <= n; j += i) {
				if (!A[j]) ans += i, A[j] = 1;
			}
		}
	}

	cout << ans;
}