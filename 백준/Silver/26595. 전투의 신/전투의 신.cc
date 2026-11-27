#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n;
	cin >> n;

	ll a, pa, b, pb;
	cin >> a >> pa >> b >> pb;

	ll ansV = 0, a1 = 0, a2 = 0;
	for (ll ix = 0; ix * pa <= n; ix++) {
		ll tn = n - ix * pa;

		ll ix2 = tn / pb;

		if (ansV < ix * a + ix2 * b) {
			ansV = ix * a + ix2 * b;
			a1 = ix, a2 = ix2;
		}
	}

	cout << a1 << ' ' << a2;

}