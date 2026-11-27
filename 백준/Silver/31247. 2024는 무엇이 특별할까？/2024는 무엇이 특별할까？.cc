#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {

		ll n, k;
		cin >> n >> k;

		if (k >= 64) cout << 0 << '\n';
		else {
			ll ans = n / (1ll << k);
			
			cout << (ans +1)/2<< '\n';


		}

	}

}