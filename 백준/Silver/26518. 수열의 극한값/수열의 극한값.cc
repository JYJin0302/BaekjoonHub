#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cout << setprecision(9) << fixed;

	ll b, c, x1, x2;
	cin >> b >> c >> x1 >> x2;;

	long double ans = 0.5 * (b + sqrtl(b * b + 4 * c));
	cout << ans;
}