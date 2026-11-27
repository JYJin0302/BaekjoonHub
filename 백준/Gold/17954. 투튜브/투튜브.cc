#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {

	ll n;
	cin >> n;

	n *= 2;
	ll d = n / 2 - 2;

	ll ans = 0, tot = n * (n+1)/2;

	ll t = 0;
	for (int i = n - 3; i > d; i--) {
		ans += t * tot;
		tot -= i;
		t++;
	}

	if (n - 2 > 0) {
		ans += t * tot;
		tot -= n - 2;
		t++;
	}

	ans += t * tot;
	tot -= n - 1;
	t++;

	for (int i = d; i >= 1; i--) {
		ans += t * tot;
		tot -= i;
		t++;
	}

	ans += t * tot;
	tot -= n;
	t++;

	cout << ans << '\n';

	if (n == 2) {
		cout << "1\n2";
		return 0;
	}

	for (int i = n - 3; i > d; i--) cout << i << ' ';
	cout << n - 2 << '\n';

	cout << n - 1 << ' ';
	for (int i = d; i >= 1; i--) cout << i << ' ';
	cout << n << '\n';

}